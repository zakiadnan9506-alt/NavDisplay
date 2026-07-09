#ifndef ICONS_H
#define ICONS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "globals.h"

namespace NavDisplay
{

// ============================================================================
// Icon Metrics
// ============================================================================

constexpr int16_t NAV_ICON_SIZE = 48;

// ============================================================================
// Navigation Icon
// ============================================================================

void drawTurnIcon(
    Adafruit_GFX& gfx,
    TurnType turn,
    int16_t x,
    int16_t y);

// ============================================================================
// Status Icons
// ============================================================================

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

} // namespace NavDisplay

#endif // ICONS_H
