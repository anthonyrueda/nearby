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

#ifndef THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_CREDENTIAL_STORAGE_H_
#define THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_CREDENTIAL_STORAGE_H_

#include <memory>
#include <tuple>
#include <vector>

#include "absl/strings/string_view.h"
#include "internal/platform/implementation/credential_storage.h"
#include "internal/platform/implementation/platform.h"

namespace location {
namespace nearby {

/*
 * The instance of CredentialStorage is owned by {@code CredentialManager}.
 * It's a wrapper on top of implementation/credential_storage.h to providing
 * credential storage operations for Nearby logic layer to invoke.
 */
class CredentialStorage {
 public:
  explicit CredentialStorage()
      : impl_(api::ImplementationPlatform::CreateCredentialStorage()) {}
  ~CredentialStorage() = default;

  // CredentialStorage class is movable but not copyable.
  CredentialStorage(CredentialStorage&& other) = default;
  CredentialStorage& operator=(CredentialStorage&& other) = default;

  void SaveCredentials(absl::string_view manager_app_id,
                       absl::string_view account_name,
                       const std::vector<::nearby::internal::PrivateCredential>&
                           private_credentials,
                       const std::vector<::nearby::internal::PublicCredential>&
                           public_credentials,
                       api::PublicCredentialType public_credential_type,
                       api::SaveCredentialsResultCallback callback);

  // Used to fetch private creds when broadcasting.
  void GetPrivateCredentials(const api::CredentialSelector& credential_selector,
                             api::GetPrivateCredentialsResultCallback callback);

  // Used to fetch remote public creds when scanning.
  void GetPublicCredentials(const api::CredentialSelector& credential_selector,
                            api::PublicCredentialType public_credential_type,
                            api::GetPublicCredentialsResultCallback callback);

 protected:
  std::vector<::nearby::internal::PrivateCredential>
  GetPrivateCredentialsForTesting(
      const std::tuple<absl::string_view, absl::string_view>& key);
  std::vector<::nearby::internal::PublicCredential>
  GetPublicCredentialsForTesting(
      const std::tuple<absl::string_view, absl::string_view,
                       api::PublicCredentialType>& key);

 private:
  std::unique_ptr<api::CredentialStorage> impl_;
};

}  // namespace nearby
}  // namespace location

#endif  // THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_CREDENTIAL_STORAGE_H_
