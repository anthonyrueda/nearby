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

#include "gtest/gtest.h"
#include "connections/device.h"

namespace location {
namespace nearby {
namespace connections {
namespace {

constexpr int kDeviceId = 12345;
constexpr char kDeviceName[] = "Sample Device";
constexpr char kDeviceImageUrl[] =
    "https://lh3.googleusercontent.com/a-/"
    "AFdZucq1YCEyL_d7GHqPweYIfql-HdjSAwbn13tmAd32xdk=s288-p-rw-no";

TEST(PresenceDeviceBuilderTest, NoDefaultConstructor) {
  EXPECT_FALSE(std::is_trivially_constructible<PresenceDeviceBuilder>::value);
}

TEST(PresenceDeviceBuilderTest, TestNoDeviceId) {
  PresenceDeviceBuilder builder;
  EXPECT_EQ(builder.Build(), nullptr);
}

TEST(PresenceDeviceBuilderTest, TestNoDeviceName) {
  PresenceDeviceBuilder builder;
  builder.SetDeviceId(kDeviceId);
  EXPECT_EQ(builder.Build(), nullptr);
}

TEST(PresenceDeviceBuilderTest, TestRandomEndpointId) {
  PresenceDeviceBuilder builder1, builder2;
  builder1.SetDeviceId(kDeviceId);
  builder1.SetDeviceName(kDeviceName);
  builder2.SetDeviceId(kDeviceId);
  builder2.SetDeviceName(kDeviceName);
  PresenceDevice* pd1 = builder1.Build();
  PresenceDevice* pd2 = builder2.Build();
  EXPECT_NE(pd1->GetEndpointId(), pd2->GetEndpointId());
  delete (pd1);
  delete (pd2);
}

TEST(PresenceDeviceBuilderTest, TestSetDeviceIdAndName) {
  PresenceDeviceBuilder builder;
  builder.SetDeviceId(kDeviceId);
  builder.SetDeviceName(kDeviceName);
  PresenceDevice* pd = builder.Build();
  EXPECT_EQ(pd->GetDeviceId(), kDeviceId);
  EXPECT_EQ(pd->GetDeviceName(), kDeviceName);
  delete (pd);
}

TEST(PresenceDeviceBuilderTest, TestSetDeviceType) {
  PresenceDeviceBuilder builder;
  builder.SetDeviceId(kDeviceId).SetDeviceName(kDeviceName);
  builder.SetDeviceType(PresenceDeviceType::kDisplay);
  PresenceDevice* pd = builder.Build();
  EXPECT_EQ(pd->GetPresenceDeviceType(), PresenceDeviceType::kDisplay);
  delete (pd);
}

TEST(PresenceDeviceBuilderTest, TestEndpointId) {
  PresenceDeviceBuilder builder;
  builder.SetDeviceId(kDeviceId).SetDeviceName(kDeviceName);
  builder.SetEndpointId("GOOG");
  PresenceDevice* pd = builder.Build();
  EXPECT_NE(pd, nullptr);
  EXPECT_EQ(pd->GetEndpointId(), "GOOG");
  delete (pd);
}

TEST(PresenceDeviceBuilderTest, TestInvalidEndpointId) {
  PresenceDeviceBuilder builder;
  builder.SetDeviceId(kDeviceId).SetDeviceName(kDeviceName);
  builder.SetEndpointId("GOOGL");
  PresenceDevice* pd = builder.Build();
  EXPECT_NE(pd, nullptr);
  EXPECT_NE(pd->GetEndpointId(), "GOOGL");
  delete(pd);
}

TEST(PresenceDeviceBuilderTest, TestDeviceImageUrl) {
  PresenceDeviceBuilder builder;
  builder.SetDeviceId(kDeviceId).SetDeviceName(kDeviceName);
  builder.SetDeviceImageUrl(kDeviceImageUrl);
  PresenceDevice* pd = builder.Build();
  EXPECT_NE(pd, nullptr);
  EXPECT_EQ(pd->GetDeviceProfileUrl(), kDeviceImageUrl);
  delete (pd);
}

TEST(PresenceDeviceBuilderTest, TestPresenceType) {
  PresenceDeviceBuilder builder;
  builder.SetDeviceId(kDeviceId).SetDeviceName(kDeviceName);
  PresenceDevice* pd = builder.Build();
  EXPECT_EQ(pd->GetType(), NearbyDevice::Type::kPresenceDevice);
  delete(pd);
}

}  // namespace
}  // namespace connections
}  // namespace nearby
}  // namespace location
