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

#ifndef THIRD_PARTY_NEARBY_CONNECTIONS_PRESENCE_DEVICE_BUILDER_H_
#define THIRD_PARTY_NEARBY_CONNECTIONS_PRESENCE_DEVICE_BUILDER_H_

#include <string>

#include "connections/device.h"
#include "internal/platform/byte_array.h"

namespace location {
namespace nearby {
namespace connections {

static const int kEndpointIdCharsSize = 36;
static const char kEndpointIdChars[kEndpointIdCharsSize] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
static const int kEndpointIdLength = 4;

class PresenceDeviceBuilder {
 public:
  PresenceDevice* Build();
  PresenceDeviceBuilder();
  PresenceDeviceBuilder& SetDeviceId(int64_t device_id);
  PresenceDeviceBuilder& SetDeviceName(const std::string& device_name);
  PresenceDeviceBuilder& SetDeviceType(PresenceDeviceType device_type);
  PresenceDeviceBuilder& SetDeviceImageUrl(const std::string& device_image_url);
  PresenceDeviceBuilder& SetEndpointId(const std::string& endpoint_id);
  PresenceDeviceBuilder& SetEndpointInfo(const ByteArray& endpoint_info);

 private:
  int64_t device_id_;
  std::string device_name_;
  PresenceDeviceType device_type_;
  std::string device_image_url_;
  std::string endpoint_id_;
  ByteArray endpoint_info_;
};

}  // namespace connections
}  // namespace nearby
}  // namespace location

#endif  // THIRD_PARTY_NEARBY_CONNECTIONS_PRESENCE_DEVICE_BUILDER_H_
