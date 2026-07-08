#ifndef ICONS_H
#define ICONS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "globals.h"

//
// ==========================================================
// ICON SIZE
// ==========================================================
//

constexpr uint8_t NAV_ICON_SIZE = 48;

//
// ==========================================================
// TURN ICON
// ==========================================================
//

void drawTurnIcon(
    Adafruit_GFX& gfx,
    TurnType turn,
    int16_t x,
    int16_t y);

//
// ==========================================================
// STATUS ICONS
// ==========================================================
//

void drawBLEIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    bool connected);

void drawGPSIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    bool gps);

void drawBatteryIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    uint8_t percent);

#endif
