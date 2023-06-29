// Copyright 2023 Google LLC
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

use windows::Devices::Bluetooth::BluetoothLEDevice;

use crate::bluetooth::common::Device;

/// Concrete type implementing `Device`, used for Windows BLE.
pub struct BleDevice {
    inner: BluetoothLEDevice,
}

impl Device for BleDevice {
    fn name(&self) -> Result<String, anyhow::Error> {
        Ok(self.inner.Name()?.to_string_lossy())
    }
}

mod tests {

    // TODO b/288592509 unit tests
}
