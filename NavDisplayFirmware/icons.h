/******************************************************************************
 *
 * NavDisplay Framework RC v1.0
 * File : icons.h
 *
 ******************************************************************************/

#ifndef ICONS_H
#define ICONS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "globals.h"

// Display object didefinisikan di display.cpp
extern Adafruit_SSD1306 display;

namespace NavDisplay
{

// ============================================================================
// Icon Metrics
// ============================================================================

constexpr int16_t NAV_ICON_SIZE = 48;

constexpr int16_t STATUS_ICON_SIZE = 10;

constexpr int16_t BATTERY_WIDTH  = 14;
constexpr int16_t BATTERY_HEIGHT = 8;

// ============================================================================
// Navigation Icon
// ============================================================================

void drawTurnIcon(
    TurnType turn,
    int16_t x,
    int16_t y);

// ============================================================================
// Status Icons
// ============================================================================

void drawBLEIcon(
    int16_t x,
    int16_t y,
    bool connected);

void drawGPSIcon(
    int16_t x,
    int16_t y,
    bool fixed);

void drawBatteryIcon(
    int16_t x,
    int16_t y,
    uint8_t percent);

// ============================================================================
// Utility
// ============================================================================

void drawArrow(
    int16_t x1,
    int16_t y1,
    int16_t x2,
    int16_t y2);

void drawRoundabout(
    int16_t x,
    int16_t y,
    uint8_t exitNumber);

} // namespace NavDisplay

#endif // ICONS_H
