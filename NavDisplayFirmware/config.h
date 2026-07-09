#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

//
// ==========================================================
// FIRMWARE INFORMATION
// ==========================================================
//

#define FW_NAME             "NavDisplay"
#define FW_VERSION          "v1.0"

//
// ==========================================================
// HARDWARE
// ==========================================================
//

#define SCREEN_WIDTH        128
#define SCREEN_HEIGHT       64

#define OLED_I2C_ADDR       0x3C

// ESP32-C3 SuperMini I2C Default
#define OLED_SDA_PIN        8
#define OLED_SCL_PIN        9

//
// ==========================================================
// BATTERY
// ==========================================================
//

#define BATTERY_ADC_PIN     0

// ADC Calibration
#define BATTERY_MIN_VOLT    3.30f
#define BATTERY_MAX_VOLT    4.20f

// Divider Ratio (ubah bila menggunakan voltage divider)
#define BATTERY_DIVIDER_RATIO   2.0f

// ADC
#define ADC_RESOLUTION      4095.0f
#define ADC_REFERENCE       3.30f

//
// ==========================================================
// BLE
// ==========================================================
//

#define BLE_DEVICE_NAME     "NavDisplay"

#define BLE_SERVICE_UUID \
"6E400001-B5A3-F393-E0A9-E50E24DCCA9E"

#define BLE_CHARACTERISTIC_RX_UUID \
"6E400002-B5A3-F393-E0A9-E50E24DCCA9E"

#define BLE_CHARACTERISTIC_TX_UUID \
"6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

//
// ==========================================================
// SERIAL
// ==========================================================
//

#define SERIAL_BAUDRATE     115200

//
// ==========================================================
// DISPLAY
// ==========================================================
//

#define DISPLAY_REFRESH_MS  50

//
// ==========================================================
// NAVIGATION
// ==========================================================
//

// Jika tidak ada data baru selama 5 detik,
// navigasi dianggap selesai.
#define GPS_TIMEOUT_MS      5000

// Panjang maksimum nama jalan
#define MAX_ROAD_LENGTH     64

//
// ==========================================================
// UI
// ==========================================================
//

#define STATUS_BAR_HEIGHT   12

#define TURN_ICON_SIZE      32

#define TEXT_SMALL          1
#define TEXT_NORMAL         1
#define TEXT_LARGE          2

//
// ==========================================================
// DEBUG
// ==========================================================
//

#define ENABLE_SERIAL_DEBUG     true

#endif
