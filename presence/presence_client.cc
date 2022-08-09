// Copyright 2020 Google LLC
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

#include "presence/presence_client.h"

#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "presence/presence_device.h"

namespace nearby {
namespace presence {

void PresenceClient::StartDiscovery(const DiscoveryFilter& filter,
                                    const DiscoveryOptions& options,
                                    ResultCallback callback) {}

void PresenceClient::UpdateDiscoveryFilter(const DiscoveryFilter& filter,
                                           ResultCallback callback) {}

void PresenceClient::StopDiscovery(ResultCallback callback) {}

std::vector<PresenceDevice> PresenceClient::GetCachedDevices(
    const DiscoveryFilter& filter) {
  return std::vector<PresenceDevice>{};
}

absl::StatusOr<BroadcastSession> PresenceClient::StartBroadcast(
    const BroadcastRequest& request, ResultCallback callback) {
  return absl::UnimplementedError("StartBroadcast unimplemented");
}

}  // namespace presence
}  // namespace nearby
