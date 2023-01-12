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

#ifndef THIRD_PARTY_NEARBY_FASTPAIR_DATAPARSER_FAST_PAIR_DECODER_H_
#define THIRD_PARTY_NEARBY_FASTPAIR_DATAPARSER_FAST_PAIR_DECODER_H_

#include <cstdint>
#include <string>
#include <vector>

#include "absl/types/optional.h"

namespace nearby {
namespace fastpair {

class FastPairDecoder {
 public:
  static bool HasModelId(const std::vector<uint8_t>* service_data);

  static absl::optional<std::string> GetHexModelIdFromServiceData(
      const std::vector<uint8_t>* service_data);
};
}  // namespace fastpair
}  // namespace nearby

#endif  // THIRD_PARTY_NEARBY_FASTPAIR_DATAPARSER_FAST_PAIR_DECODER_H_
