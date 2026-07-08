#ifndef ICONS_H
#define ICONS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "navigation.h"

//
// ==========================================================
// NavDisplay Framework v1.0
// Icon Renderer
// ==========================================================
//
// Semua bitmap disimpan pada icons.cpp menggunakan PROGMEM.
//
// File ini hanya mengekspos API rendering sehingga modul
// lain tidak mengetahui detail implementasi bitmap.
//
// ==========================================================
//

constexpr uint8_t NAV_ICON_SIZE = 48;

//
// Navigation
//
void drawTurnIcon(
    Adafruit_GFX& display,
    TurnType turn,
    int16_t x,
    int16_t y);

//
// BLE
//
void drawBLEIcon(
    Adafruit_GFX& display,
    int16_t x,
    int16_t y,
    bool connected);

//
// GPS
//
void drawGPSIcon(
    Adafruit_GFX& display,
    int16_t x,
    int16_t y,
    bool gps);

//
// Battery
//
void drawBatteryIcon(
    Adafruit_GFX& display,
    int16_t x,
    int16_t y,
    uint8_t percent);

#endif
