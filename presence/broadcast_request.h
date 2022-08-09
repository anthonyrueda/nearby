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

#ifndef THIRD_PARTY_NEARBY_PRESENCE_BROADCAST_REQUEST_H_
#define THIRD_PARTY_NEARBY_PRESENCE_BROADCAST_REQUEST_H_

#include <string>
#include <vector>

#include "absl/types/optional.h"
#include "presence/data_element.h"
#include "presence/power_mode.h"
#include "presence/presence_identity.h"

namespace nearby {
namespace presence {

// Nearby Presence advertisement request options.
struct BroadcastRequest {
  // Calibrated TX power. The broadcast recipient uses it to calculate the
  // distance between both devices.
  int tx_power;

  // Account name used to select private credentials.
  std::string account_name;

  // Presence identity type.
  absl::optional<PresenceIdentity> identity;

  // The broadcast frequency hint.
  PowerMode power_mode;

  // Additional Data Elements.
  // The Presence SDK generates:
  // - Salt,
  // - (Private/Trusted/Public/Provisioned) Identity,
  // - TX power,
  // - Adverisement signature
  // Data Elements when they are required in the advertisement. Other Data
  // Elements are provided by the client application.
  // Nearby SDK encrypts Data ELements before broadcasting if a non-public
  // `PresenceIdentity` is provided.
  std::vector<DataElement> extended_properties;
};

}  // namespace presence
}  // namespace nearby
#endif  // THIRD_PARTY_NEARBY_PRESENCE_BROADCAST_REQUEST_H_
