// Copyright 2022 Google LLC
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

#include "connections/presence_device_builder.h"

#include <string>

#include "connections/device.h"
#include "internal/platform/implementation/system_clock.h"
#include "internal/platform/logging.h"
#include "internal/platform/prng.h"

namespace location {
namespace nearby {
namespace connections {

PresenceDeviceBuilder::PresenceDeviceBuilder() {
  device_id_ = -1;
  device_name_ = "";
  device_type_ = PresenceDeviceType::kUnknown;
  device_image_url_ = "";
  endpoint_id_ = "";
  endpoint_info_ = ByteArray();
}

PresenceDeviceBuilder& PresenceDeviceBuilder::SetDeviceId(int64_t device_id) {
  device_id_ = device_id;
  return *this;
}

PresenceDeviceBuilder& PresenceDeviceBuilder::SetDeviceName(
    const std::string& device_name) {
  device_name_ = device_name;
  return *this;
}

PresenceDeviceBuilder& PresenceDeviceBuilder::SetDeviceType(
    PresenceDeviceType type) {
  device_type_ = type;
  return *this;
}

PresenceDeviceBuilder& PresenceDeviceBuilder::SetDeviceImageUrl(
    const std::string& image_url) {
  device_image_url_ = image_url;
  return *this;
}

PresenceDeviceBuilder& PresenceDeviceBuilder::SetEndpointId(
    const std::string& endpoint_id) {
  if (endpoint_id.length() != kEndpointIdLength) {
    NEARBY_LOGS(ERROR) << "Endpoint ID must be of length 4.";
    return *this;
  }
  endpoint_id_ = endpoint_id;
  return *this;
}

PresenceDeviceBuilder& PresenceDeviceBuilder::SetEndpointInfo(
    const ByteArray& endpoint_info) {
  endpoint_info_ = endpoint_info;
  return *this;
}

std::string GenerateEndpointId() {
  Prng rng;
  char gen_id[kEndpointIdLength];
  for (int i = 0; i < kEndpointIdLength; ++i) {
    gen_id[i] = kEndpointIdChars[rng.NextUint32() % kEndpointIdCharsSize];
  }
  return gen_id;
}

PresenceDevice* PresenceDeviceBuilder::Build() {
  if (device_id_ == -1) {
    NEARBY_LOGS(ERROR) << "PresenceDevice ID must be set.";
    return nullptr;
  }
  if (device_name_.empty()) {
    NEARBY_LOGS(ERROR) << "PresenceDevice name must be set.";
    return nullptr;
  }
  if (endpoint_id_.empty()) {
    endpoint_id_ = GenerateEndpointId();
  }
  return new PresenceDevice(
      endpoint_id_, endpoint_info_, device_type_, device_id_, device_name_,
      device_image_url_,
      /* discovery_time */ absl::ToUnixMillis(SystemClock::ElapsedRealtime()));
}
}  // namespace connections
}  // namespace nearby
}  // namespace location
