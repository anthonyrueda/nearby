// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "absl/strings/string_view.h"
#include "internal/platform/implementation/windows/wifi_hotspot.h"

// Nearby connections headers
#include "internal/platform/cancellation_flag_listener.h"
#include "internal/platform/implementation/windows/utils.h"
#include "internal/platform/logging.h"

namespace location {
namespace nearby {
namespace windows {

namespace {
constexpr int kMaxRetries = 3;
constexpr int kRetryIntervalMilliSeconds = 300;
constexpr int kMaxScans = 2;
}  // namespace

WifiHotspotMedium::WifiHotspotMedium() {}

WifiHotspotMedium::~WifiHotspotMedium() {
  StopWifiHotspot();
  DisconnectWifiHotspot();
}

bool WifiHotspotMedium::IsInterfaceValid() const {
  // Windows 10 starts to support WiFi direct feature, so don't need to check
  // feature by OS due to targeting OS version is at leat Windows 10.
  NEARBY_LOGS(ERROR) << "WiFi hotspot: valid interface found.";
  return true;
}

std::unique_ptr<api::WifiHotspotSocket> WifiHotspotMedium::ConnectToService(
    absl::string_view ip_address, int port,
    CancellationFlag* cancellation_flag) {
  if (ip_address.empty() || port == 0) {
    NEARBY_LOGS(ERROR) << "no valid service address and port to connect: "
                       << "ip_address = " << ip_address << ", port = " << port;
    return nullptr;
  }

  std::string ipv4_address;
  if (ip_address.length() == 4) {
    ipv4_address = ipaddr_4bytes_to_dotdecimal_string(ip_address);
  } else {
    ipv4_address = std::string(ip_address);
  }
  if (ipv4_address.empty()) {
    NEARBY_LOGS(ERROR) << "Invalid IP address parameter.";
    return nullptr;
  }

  HostName host_name{winrt::to_hstring(ipv4_address)};
  winrt::hstring service_name{winrt::to_hstring(port)};

  StreamSocket socket{};

  // setup cancel listener
  if (cancellation_flag != nullptr) {
    if (cancellation_flag->Cancelled()) {
      NEARBY_LOGS(INFO) << "connect has been cancelled to service "
                        << ipv4_address << ":" << port;
      return nullptr;
    }

    location::nearby::CancellationFlagListener cancellationFlagListener(
        cancellation_flag, [socket]() { socket.CancelIOAsync().get(); });
  }

  // Try connecting to the service up to kMaxRetries, because it may fail
  // first time if DHCP procedure is not finished yet.
  for (int i = 0; i < kMaxRetries; i++) {
    try {
      Sleep(kRetryIntervalMilliSeconds);
      socket.ConnectAsync(host_name, service_name).get();

      auto wifi_hotspot_socket = std::make_unique<WifiHotspotSocket>(socket);

      NEARBY_LOGS(INFO) << "connected to remote service " << ipv4_address << ":"
                        << port;
      return wifi_hotspot_socket;
    } catch (...) {
      NEARBY_LOGS(ERROR) << "failed to connect remote service " << ipv4_address
                         << ":" << port << " for the " << i + 1 << " time";
    }
  }
  return nullptr;
}

std::unique_ptr<api::WifiHotspotServerSocket>
WifiHotspotMedium::ListenForService(int port) {
  absl::MutexLock lock(&mutex_);

  // check current status
  if (IsAccepting()) {
    NEARBY_LOGS(WARNING) << "accepting connections already started on port "
                         << server_socket_ptr_->GetPort();
    return nullptr;
  }

  auto server_socket = std::make_unique<WifiHotspotServerSocket>(port);
  server_socket_ptr_ = server_socket.get();

  server_socket->SetCloseNotifier([this]() {
    absl::MutexLock lock(&mutex_);
    NEARBY_LOGS(INFO) << "server socket was closed on port "
                      << server_socket_ptr_->GetPort();
    medium_status_ &= (~kMediumStatusAccepting);
    server_socket_ptr_ = nullptr;
  });

  if (server_socket->listen()) {
    medium_status_ |= kMediumStatusAccepting;
    NEARBY_LOGS(INFO) << "started to listen serive on port "
                      << server_socket_ptr_->GetPort();
    return server_socket;
  }

  NEARBY_LOGS(ERROR) << "Failed to listen service on port " << port;

  return nullptr;
}

bool WifiHotspotMedium::StartWifiHotspot(
    HotspotCredentials* hotspot_credentials_) {
  absl::MutexLock lock(&mutex_);

  if (IsBeaconing()) {
    NEARBY_LOGS(WARNING) << "cannot create SoftAP again when it is running.";
    return true;
  }

  publisher_ = WiFiDirectAdvertisementPublisher();
  publisher_status_changed_token_ =
      publisher_.StatusChanged({this, &WifiHotspotMedium::OnStatusChanged});
  listener_ = WiFiDirectConnectionListener();
  connection_requested_token_ = listener_.ConnectionRequested(
      {this, &WifiHotspotMedium::OnConnectionRequested});

  // Normal mode: The device is highly discoverable so long as the app is in
  // the foreground.
  publisher_.Advertisement().ListenStateDiscoverability(
      WiFiDirectAdvertisementListenStateDiscoverability::Normal);
  // Enbale Autonomous GO mode
  publisher_.Advertisement().IsAutonomousGroupOwnerEnabled(true);

  // Using WIFIDirect legacy mode to create a softAP. AP means "access point".
  publisher_.Advertisement().LegacySettings().IsEnabled(true);
  std::string password = absl::StrFormat("%08x", Prng().NextUint32());
  hotspot_credentials_->SetPassword(password);
  PasswordCredential creds;
  creds.Password(winrt::to_hstring(password));
  publisher_.Advertisement().LegacySettings().Passphrase(creds);

  std::string ssid = "DIRECT-" + std::to_string(Prng().NextUint32());
  hotspot_credentials_->SetSSID(ssid);
  publisher_.Advertisement().LegacySettings().Ssid(winrt::to_hstring(ssid));

  publisher_.Start();
  if (publisher_.Status() == WiFiDirectAdvertisementPublisherStatus::Started) {
    NEARBY_LOGS(INFO) << "Windows WiFi Hotspot started";
    medium_status_ |= kMediumStatusBeaconing;

    return true;
  }

  // Clean up when fail
  NEARBY_LOGS(ERROR) << "Windows WiFi Hotspot fails to start";
  publisher_.StatusChanged(publisher_status_changed_token_);
  listener_.ConnectionRequested(connection_requested_token_);
  listener_ = nullptr;
  publisher_ = nullptr;
  return false;
}

bool WifiHotspotMedium::StopWifiHotspot() {
  // Need to use Win32 API to deregister the Dnssd instance
  absl::MutexLock lock(&mutex_);

  if (!IsBeaconing()) {
    NEARBY_LOGS(WARNING) << "Cannot stop SoftAP because no SoftAP is started.";
    return true;
  }

  if (publisher_) {
    publisher_.Stop();
    listener_.ConnectionRequested(connection_requested_token_);
    publisher_.StatusChanged(publisher_status_changed_token_);
    wifi_direct_device_  = nullptr;
    listener_ = nullptr;
    publisher_ = nullptr;
    NEARBY_LOGS(INFO) << "succeeded to stop WiFi Hotspot";
  }

  medium_status_ &= (~kMediumStatusBeaconing);
  return true;
}

fire_and_forget WifiHotspotMedium::OnStatusChanged(
    WiFiDirectAdvertisementPublisher sender,
    WiFiDirectAdvertisementPublisherStatusChangedEventArgs event) {
  if (event.Status() == WiFiDirectAdvertisementPublisherStatus::Started) {
    if (sender.Advertisement().LegacySettings().IsEnabled()) {
      NEARBY_LOGS(INFO)
          << "WiFi SoftAP SSID: "
          << winrt::to_string(
                 publisher_.Advertisement().LegacySettings().Ssid());
      NEARBY_LOGS(INFO) << "WiFi SoftAP PW: "
                        << winrt::to_string(publisher_.Advertisement()
                                                .LegacySettings()
                                                .Passphrase()
                                                .Password());
    }
    return winrt::fire_and_forget();
  } else if (event.Status() ==
             WiFiDirectAdvertisementPublisherStatus::Created) {
    NEARBY_LOGS(INFO) << "Receive WiFi direct/SoftAP Created event.";
    return winrt::fire_and_forget();
  } else if (event.Status() ==
             WiFiDirectAdvertisementPublisherStatus::Stopped) {
    NEARBY_LOGS(INFO) << "Receive WiFi direct/SoftAP Stopped event.";
  } else if (event.Status() ==
             WiFiDirectAdvertisementPublisherStatus::Aborted) {
    NEARBY_LOGS(INFO) << "Receive WiFi direct/SoftAP Aborted event.";
  }

  // Publisher is stopped. Need to clean up the publisher.
  {
    absl::MutexLock lock(&mutex_);
    if (publisher_ != nullptr) {
      NEARBY_LOGS(ERROR) << "Windows WiFi Hotspot cleanup.";
      listener_.ConnectionRequested(connection_requested_token_);
      publisher_.StatusChanged(publisher_status_changed_token_);
      wifi_direct_device_  = nullptr;
      listener_ = nullptr;
      publisher_ = nullptr;
    }
  }

  return winrt::fire_and_forget();
}

fire_and_forget WifiHotspotMedium::OnConnectionRequested(
    WiFiDirectConnectionListener const& sender,
    WiFiDirectConnectionRequestedEventArgs const& event) {
  WiFiDirectConnectionRequest connection_request = event.GetConnectionRequest();
  winrt::hstring device_name = connection_request.DeviceInformation().Name();
  NEARBY_LOGS(INFO) << "Receive connection request from: "
                    << winrt::to_string(device_name);

  try {
    // This is to solve b/236805122.
    // Problem: [Microsoft-Windows-WLAN-AutoConfig] issues a disconnection to
    // Hotspot Client every 2 minutes and stopped Hotspot eventually.
    // Solution: Creating a WiFiDirectDevice for Client’s connection request can
    // solve the problem. Guess when this object is created,
    // [Microsoft-Windows-WLAN-AutoConfig] will recognise it as a valid device
    // and won't kick it away.
    wifi_direct_device_  = WiFiDirectDevice::FromIdAsync(
            connection_request.DeviceInformation().Id()).get();
    NEARBY_LOGS(INFO) << "Registered the device in WLAN-AutoConfig";
  } catch (...) {
    NEARBY_LOGS(ERROR) << "Failed to registered the device in WLAN-AutoConfig";
    wifi_direct_device_  = nullptr;
    connection_request.Close();
  }
  return winrt::fire_and_forget();
}

bool WifiHotspotMedium::ConnectWifiHotspot(
    HotspotCredentials* hotspot_credentials_) {
  absl::MutexLock lock(&mutex_);

  if (IsConnected()) {
    NEARBY_LOGS(WARNING) << "Already connected to AP, disconnect first.";
    InternalDisconnectWifiHotspot();
  }

  auto access = WiFiAdapter::RequestAccessAsync().get();
  if (access != WiFiAccessStatus::Allowed) {
    NEARBY_LOGS(WARNING) << "Access Denied with reason: "
                         << static_cast<int>(access);
    return false;
  }

  auto adapters = WiFiAdapter::FindAllAdaptersAsync().get();
  if (adapters.Size() < 1) {
    NEARBY_LOGS(WARNING) << "No WiFi Adapter found.";
    return false;
  }
  wifi_adapter_ = adapters.GetAt(0);

  // Retrieve the current connected network's profile
  ConnectionProfile profile =
      wifi_adapter_.NetworkAdapter().GetConnectedProfileAsync().get();
  std::string ssid;

  if (profile != nullptr && profile.IsWlanConnectionProfile()) {
    ssid = winrt::to_string(
        profile.WlanConnectionProfileDetails().GetConnectedSsid());
  }

  // SoftAP is an abbreviation for "software enabled access point".
  WiFiAvailableNetwork nearby_softap{nullptr};
  NEARBY_LOGS(INFO) << "Scanning for Nearby Hotspot SSID: "
                    << hotspot_credentials_->GetSSID();

  // First time scan may not find our target hotspot, try 2 more times can
  // almost guarantee to find the Hotspot
  wifi_adapter_.ScanAsync().get();

    wifi_connected_network_ = nullptr;
    for (int i = 0; i < kMaxScans; i++) {
    for (const auto& network :
         wifi_adapter_.NetworkReport().AvailableNetworks()) {
      if (!wifi_connected_network_ && !ssid.empty() &&
          (winrt::to_string(network.Ssid()) == ssid)) {
        wifi_connected_network_ = network;
        NEARBY_LOGS(INFO) << "Save the current connected network: " << ssid;
      } else if (!nearby_softap && winrt::to_string(network.Ssid()) ==
                                      hotspot_credentials_->GetSSID()) {
        NEARBY_LOGS(INFO) << "Found Nearby SSID: "
                          << winrt::to_string(network.Ssid());
        nearby_softap = network;
      }
      if (nearby_softap && wifi_connected_network_) break;
    }
    if (nearby_softap) break;
    NEARBY_LOGS(INFO) << "Scan ... ";
    wifi_adapter_.ScanAsync().get();
  }

  if (!nearby_softap) {
    NEARBY_LOGS(INFO) << "Hotspot is not found";
    return false;
  }

  PasswordCredential creds;
  creds.Password(winrt::to_hstring(hotspot_credentials_->GetPassword()));

  auto connect_result =
      wifi_adapter_
          .ConnectAsync(nearby_softap, WiFiReconnectionKind::Manual, creds)
          .get();

  if (connect_result == nullptr ||
      connect_result.ConnectionStatus() != WiFiConnectionStatus::Success) {
    NEARBY_LOGS(INFO) << "Connecting failed with reason: "
                      << static_cast<int>(connect_result.ConnectionStatus());
    return false;
  }

  std::string last_ssid = hotspot_credentials_->GetSSID();
  medium_status_ |= kMediumStatusConnected;
  NEARBY_LOGS(INFO) << "Connected to hotspot: " << last_ssid;

  return true;
}

bool WifiHotspotMedium::DisconnectWifiHotspot() {
  absl::MutexLock lock(&mutex_);
  return InternalDisconnectWifiHotspot();
}

bool WifiHotspotMedium::InternalDisconnectWifiHotspot() {
  if (!IsConnected()) {
    NEARBY_LOGS(WARNING)
        << "Cannot disconnect SoftAP because it is not connected.";
    return true;
  }

  if (wifi_adapter_) {
    // Gets connected WiFi profile.
    auto profile =
        wifi_adapter_.NetworkAdapter().GetConnectedProfileAsync().get();

    // Disconnect to the WiFi connection through the WiFi adapter.
    wifi_adapter_.Disconnect();
    NEARBY_LOGS(INFO) << "Disconnected to SoftAP.";

    if (wifi_connected_network_) {
      auto connect_result = wifi_adapter_
                                .ConnectAsync(wifi_connected_network_,
                                              WiFiReconnectionKind::Automatic)
                                .get();

      if (connect_result == nullptr ||
          connect_result.ConnectionStatus() != WiFiConnectionStatus::Success) {
        NEARBY_LOGS(INFO)
            << "Connecting to previous network failed with reason: "
            << static_cast<int>(connect_result.ConnectionStatus());
      } else {
        NEARBY_LOGS(INFO) << "Restored the previous WIFI connection: "
                          << winrt::to_string(wifi_connected_network_.Ssid());
      }
      wifi_connected_network_ = nullptr;
    }
    wifi_adapter_ = nullptr;

    // Try to remove the WiFi profile
    if (profile != nullptr && profile.CanDelete() &&
        profile.IsWlanConnectionProfile()) {
      std::string ssid = winrt::to_string(
          profile.WlanConnectionProfileDetails().GetConnectedSsid());

      auto profile_delete_status = profile.TryDeleteAsync().get();
      switch (profile_delete_status) {
        case ConnectionProfileDeleteStatus::Success:
          NEARBY_LOGS(INFO)
              << "WiFi profile with SSID:" << ssid << " is deleted.";
          break;
        case ConnectionProfileDeleteStatus::DeniedBySystem:
          NEARBY_LOGS(ERROR)
              << "Failed to delete WiFi profile with SSID:" << ssid
              << " due to denied by system.";
          break;
        case ConnectionProfileDeleteStatus::DeniedByUser:
          NEARBY_LOGS(ERROR)
              << "Failed to delete WiFi profile with SSID:" << ssid
              << " due to denied by user.";
          break;
        case ConnectionProfileDeleteStatus::UnknownError:
          NEARBY_LOGS(ERROR)
              << "Failed to delete WiFi profile with SSID:" << ssid
              << " due to unknonw error.";
          break;
        default:
          break;
      }
    }
  }

  medium_status_ &= (~kMediumStatusConnected);
  return true;
}

std::string WifiHotspotMedium::GetErrorMessage(std::exception_ptr eptr) {
  try {
    if (eptr) {
      std::rethrow_exception(eptr);
    } else {
      return "";
    }
  } catch (const std::exception& e) {
    return e.what();
  }
}

}  // namespace windows
}  // namespace nearby
}  // namespace location
