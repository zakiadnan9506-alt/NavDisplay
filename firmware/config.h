#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

//
// ==========================================================
// PROJECT INFORMATION
// ==========================================================
//

#define FW_NAME        "NavDisplay"
#define FW_VERSION     "1.0.0"

//
// ==========================================================
// HARDWARE
// ==========================================================
//

// OLED SSD1306
#define SCREEN_WIDTH   128
#define SCREEN_HEIGHT  64

#define OLED_I2C_ADDR  0x3C

// ESP32-C3 SuperMini I2C Default
#define OLED_SDA_PIN   8
#define OLED_SCL_PIN   9

//
// ==========================================================
// BATTERY
// ==========================================================
//

#define BATTERY_ADC_PIN     0

// ADC calibration
#define BATTERY_MIN_VOLT    3.30f
#define BATTERY_MAX_VOLT    4.20f

//
// ==========================================================
// BLE
// ==========================================================
//

// Device Name
#define BLE_DEVICE_NAME     "NavDisplay"

// UUID Service
#define BLE_SERVICE_UUID            "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"

// RX Characteristic
#define BLE_CHARACTERISTIC_RX_UUID  "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"

// TX Characteristic
#define BLE_CHARACTERISTIC_TX_UUID  "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

//
// ==========================================================
// SERIAL
// ==========================================================
//

#define SERIAL_BAUDRATE     115200

//
// ==========================================================
// DISPLAY UPDATE
// ==========================================================
//

#define DISPLAY_REFRESH_MS  100

//
// ==========================================================
// NAVIGATION DEFAULTS
// ==========================================================
//

#define DEFAULT_DISTANCE       0
#define DEFAULT_SPEED          0
#define DEFAULT_ETA_MINUTES    0

//
// ==========================================================
// TIMEOUTS
// ==========================================================
//

#define BLE_TIMEOUT_MS         15000
#define GPS_TIMEOUT_MS         5000

//
// ==========================================================
// DEBUG
// ==========================================================
//

// 1 = Enable Serial Debug
// 0 = Disable Debug

#define DEBUG_SERIAL 1

#if DEBUG_SERIAL
    #define DEBUG_PRINT(x)     Serial.print(x)
    #define DEBUG_PRINTLN(x)   Serial.println(x)
    #define DEBUG_PRINTF(...)  Serial.printf(__VA_ARGS__)
#else
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINTLN(x)
    #define DEBUG_PRINTF(...)
#endif

#endif
