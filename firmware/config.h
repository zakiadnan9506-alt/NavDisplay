#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

/*
=====================================================
PROJECT
=====================================================
*/

#define PROJECT_NAME           "NavDisplay"

#define FW_MAJOR               1
#define FW_MINOR               0
#define FW_PATCH               0

/*
=====================================================
OLED SSD1306
=====================================================
*/

#define SCREEN_WIDTH           128
#define SCREEN_HEIGHT          64

#define OLED_ADDRESS           0x3C

// ESP32-C3 SuperMini
#define OLED_SDA               8
#define OLED_SCL               9

/*
=====================================================
BLE
=====================================================
*/

#define BLE_DEVICE_NAME        "NavDisplay"

#define BLE_SERVICE_UUID       "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"

#define BLE_RX_UUID            "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"

#define BLE_TX_UUID            "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

/*
=====================================================
DISPLAY
=====================================================
*/

#define DISPLAY_FPS            25

#define DISPLAY_REFRESH_MS     40

/*
=====================================================
NAVIGATION
=====================================================
*/

#define MAX_ROAD_NAME          32

/*
=====================================================
SERIAL
=====================================================
*/

#define SERIAL_BAUDRATE        115200

#endif// Placeholder - will be filled in subsequent steps.
