# NavDisplay

NavDisplay adalah sistem navigasi turn-by-turn berbasis **ESP32-C3 SuperMini** dan **iPhone**.

Firmware menerima instruksi navigasi melalui Bluetooth Low Energy (BLE), kemudian menampilkan arah belok, jarak, dan nama jalan pada layar OLED SSD1306 128×64.

## Fitur

- Turn-by-turn navigation
- Bluetooth Low Energy (BLE)
- OLED SSD1306 128×64
- Binary protocol (tanpa JSON)
- ESP32-C3 SuperMini
- Arduino IDE 2.x
- iPhone (SwiftUI)

## Hardware

- ESP32-C3 SuperMini
- OLED SSD1306 128×64 (I2C)
- iPhone 8 atau lebih baru

## Software

### Firmware

- Arduino IDE 2.x
- ESP32 Board Package 3.3.10
- NimBLE-Arduino 2.5.0
- Adafruit GFX
- Adafruit SSD1306

### iOS

- Xcode
- SwiftUI
- CoreBluetooth
- Mapbox Navigation SDK

## Struktur Repository

```
firmware/
ios/
docs/
hardware/
```

## Status

🚧 Dalam pengembangan

Target akhir:

- Firmware ESP32 stabil
- Aplikasi iPhone
- Navigasi real-time melalui BLE
