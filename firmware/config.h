#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

/*=====================================================
  PROJECT
=====================================================*/

#define PROJECT_NAME        "NavDisplay"

#define FW_VERSION_MAJOR    1
#define FW_VERSION_MINOR    0
#define FW_VERSION_PATCH    0

/*=====================================================
  SERIAL
=====================================================*/

#define SERIAL_BAUDRATE     115200

/*=====================================================
  OLED SSD1306
=====================================================*/

#define SCREEN_WIDTH        128
#define SCREEN_HEIGHT       64

#define OLED_I2C_ADDRESS    0x3C

/*
 * ESP32-C3 SuperMini
 *
 * Jika OLED tidak tampil,
 * ubah pin berikut sesuai board Anda.
 */
#ifndef OLED_SDA_PIN
#define OLED_SDA_PIN        8
#endif

#ifndef OLED_SCL_PIN
#define OLED_SCL_PIN        9
#endif

/*=====================================================
  DISPLAY
=====================================================*/

#define DISPLAY_REFRESH_MS  40

/*=====================================================
  BLE
=====================================================*/

#define BLE_DEVICE_NAME     "NavDisplay"

#define BLE_SERVICE_UUID \
"4FAFC201-1FB5-459E-8FCC-C5C9C331914B"

#define BLE_CHARACTERISTIC_RX \
"BEB5483E-36E1-4688-B7F5-EA07361B26A8"

#define BLE_CHARACTERISTIC_TX \
"7E6A9F55-8D42-4D39-8B74-74A6C1F4C901"

/*=====================================================
  NAVIGATION
=====================================================*/

#define ROAD_NAME_LENGTH    48

#define DISTANCE_MAX        9999

/*=====================================================
  APPLICATION
=====================================================*/

#define SPLASH_TIMEOUT_MS   1500

#endif
