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

#ifndef CORE_INTERNAL_SERVICE_ID_CONSTANTS_H_
#define CORE_INTERNAL_SERVICE_ID_CONSTANTS_H_

#include "absl/strings/match.h"
#include "absl/strings/string_view.h"

namespace location {
namespace nearby {
namespace connections {

constexpr absl::string_view kUnknownServiceId = "UNKNOWN_SERVICE";

// A suffix appended to service IDs when initiating a bandwidth upgrade to
// distinguish the mediums from those used for advertising/discovery.
constexpr absl::string_view kInitiatorUpgradeServiceIdPostfix = "_UPGRADE";

// Returns true if |service_id| not empty and has the initiator's upgrade
// postfix.
inline bool IsInitiatorUpgradeServiceId(absl::string_view service_id) {
  return !service_id.empty() &&
         absl::EndsWith(service_id, kInitiatorUpgradeServiceIdPostfix);
}

}  // namespace connections
}  // namespace nearby
}  // namespace location

#endif  // CORE_INTERNAL_SERVICE_ID_CONSTANTS_H_
