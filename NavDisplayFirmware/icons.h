#ifndef ICONS_H
#define ICONS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "globals.h"

//
// ==========================================================
// TURN ICONS
// ==========================================================
//

void drawTurnIcon(
    Adafruit_GFX& gfx,
    TurnType turn,
    int16_t x,
    int16_t y
);

//
// ==========================================================
// STATUS ICONS
// ==========================================================
//

void drawBLEIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    bool connected
);

void drawGPSIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    bool available
);

void drawBatteryIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    uint8_t percent
);

#endif
