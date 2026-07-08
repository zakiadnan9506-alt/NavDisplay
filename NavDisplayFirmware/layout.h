#ifndef LAYOUT_H
#define LAYOUT_H

#include <Arduino.h>
#include "config.h"

//
// ==========================================================
// NavDisplay Framework v1.0
// Layout Engine
// ==========================================================
//
// Semua ukuran UI disimpan di sini agar display.cpp
// tidak memiliki magic number.
//
// Target:
// - SSD1306 128x64
// - ESP32-C3
// - Arduino ESP32 Core 3.3.x
//
// ==========================================================
//

namespace Layout
{

// ----------------------------------------------------------
// Display
// ----------------------------------------------------------

constexpr int16_t ScreenWidth  = SCREEN_WIDTH;
constexpr int16_t ScreenHeight = SCREEN_HEIGHT;

// ----------------------------------------------------------
// Safe Area
// ----------------------------------------------------------

constexpr int16_t MarginLeft   = 4;
constexpr int16_t MarginRight  = 4;
constexpr int16_t MarginTop    = 2;
constexpr int16_t MarginBottom = 2;

// ----------------------------------------------------------
// Status Bar
// ----------------------------------------------------------

constexpr int16_t StatusBarHeight = STATUS_BAR_HEIGHT;

constexpr int16_t StatusIconY = 2;
constexpr int16_t BatteryX = 108;
constexpr int16_t BatteryY = 2;

constexpr int16_t BLEIconX = 4;
constexpr int16_t BLEIconY = 2;

constexpr int16_t GPSIconX = 18;
constexpr int16_t GPSIconY = 2;

// ----------------------------------------------------------
// Main Content
// ----------------------------------------------------------

constexpr int16_t ContentTop =
    StatusBarHeight + 2;

constexpr int16_t ContentBottom =
    ScreenHeight - MarginBottom;

// ----------------------------------------------------------
// Navigation Screen
// ----------------------------------------------------------

constexpr int16_t TurnIconX = 2;
constexpr int16_t TurnIconY = 18;

constexpr int16_t TurnIconSize = TURN_ICON_SIZE;

constexpr int16_t DistanceX = 40;
constexpr int16_t DistanceY = 18;

constexpr int16_t RoadNameX = 40;
constexpr int16_t RoadNameY = 40;

constexpr int16_t FooterY = 56;

// ----------------------------------------------------------
// Waiting Screen
// ----------------------------------------------------------

constexpr int16_t WaitingIconY = 14;
constexpr int16_t WaitingTextY = 48;

// ----------------------------------------------------------
// Boot Screen
// ----------------------------------------------------------

constexpr int16_t LogoY = 8;
constexpr int16_t VersionY = 52;

// ----------------------------------------------------------
// Idle Screen
// ----------------------------------------------------------

constexpr int16_t ClockY = 18;
constexpr int16_t IdleTextY = 46;

// ----------------------------------------------------------
// Font Scale
// ----------------------------------------------------------

constexpr uint8_t FontSmall  = 1;
constexpr uint8_t FontNormal = 1;
constexpr uint8_t FontLarge  = 2;
constexpr uint8_t FontXL     = 3;

// ----------------------------------------------------------
// Animation
// ----------------------------------------------------------

constexpr uint16_t SplashDuration = 1200;
constexpr uint16_t FadeStepMs     = 16;
constexpr uint16_t BlinkPeriodMs  = 500;

// ----------------------------------------------------------
// Helpers
// ----------------------------------------------------------

inline constexpr int16_t centerX(int16_t width)
{
    return (ScreenWidth - width) / 2;
}

inline constexpr int16_t centerY(int16_t height)
{
    return (ScreenHeight - height) / 2;
}

inline constexpr int16_t contentWidth()
{
    return ScreenWidth - MarginLeft - MarginRight;
}

inline constexpr int16_t contentHeight()
{
    return ScreenHeight
           - StatusBarHeight
           - MarginBottom;
}

} // namespace Layout

#endif
