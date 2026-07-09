#ifndef LAYOUT_H
#define LAYOUT_H

#include <Arduino.h>
#include "config.h"

namespace Layout
{

// ============================================================================
// Display
// ============================================================================

constexpr int16_t ScreenWidth  = SCREEN_WIDTH;
constexpr int16_t ScreenHeight = SCREEN_HEIGHT;

// ============================================================================
// Margins
// ============================================================================

constexpr int16_t MarginLeft   = 4;
constexpr int16_t MarginRight  = 4;
constexpr int16_t MarginTop    = 2;
constexpr int16_t MarginBottom = 2;

// ============================================================================
// Status Bar
// ============================================================================

constexpr int16_t StatusBarHeight = STATUS_BAR_HEIGHT;

constexpr int16_t StatusBarTop    = 0;
constexpr int16_t StatusBarBottom = StatusBarHeight;

constexpr int16_t StatusIconY = MarginTop;

constexpr int16_t BLEIconX = MarginLeft;
constexpr int16_t BLEIconY = StatusIconY;

constexpr int16_t GPSIconX = BLEIconX + 14;
constexpr int16_t GPSIconY = StatusIconY;

constexpr int16_t BatteryX = ScreenWidth - MarginRight - 16;
constexpr int16_t BatteryY = StatusIconY;

// ============================================================================
// Content Area
// ============================================================================

constexpr int16_t ContentLeft   = MarginLeft;
constexpr int16_t ContentTop    = StatusBarHeight + 2;
constexpr int16_t ContentRight  = ScreenWidth - MarginRight;
constexpr int16_t ContentBottom = ScreenHeight - MarginBottom;

constexpr int16_t ContentWidth =
    ContentRight - ContentLeft;

constexpr int16_t ContentHeight =
    ContentBottom - ContentTop;

// ============================================================================
// Navigation Screen
// ============================================================================

constexpr int16_t TurnIconX = ContentLeft;
constexpr int16_t TurnIconY = ContentTop + 4;

constexpr int16_t TurnIconSize = TURN_ICON_SIZE;

constexpr int16_t DistanceX = TurnIconX + TurnIconSize + 6;
constexpr int16_t DistanceY = TurnIconY;

constexpr int16_t RoadNameX = DistanceX;
constexpr int16_t RoadNameY = ContentTop + 26;

constexpr int16_t FooterY = ScreenHeight - 8;

// ============================================================================
// Waiting Screen
// ============================================================================

constexpr int16_t WaitingIconY = ContentTop + 2;
constexpr int16_t WaitingTextY = ScreenHeight - 16;

// ============================================================================
// Boot Screen
// ============================================================================

constexpr int16_t LogoY    = 8;
constexpr int16_t VersionY = ScreenHeight - 12;

// ============================================================================
// Idle Screen
// ============================================================================

constexpr int16_t ClockY    = ContentTop + 4;
constexpr int16_t IdleTextY = ScreenHeight - 18;

// ============================================================================
// Font Scale
// ============================================================================

constexpr uint8_t FontSmall  = 1;
constexpr uint8_t FontNormal = 1;
constexpr uint8_t FontLarge  = 2;
constexpr uint8_t FontXL     = 3;

// ============================================================================
// Animation
// ============================================================================

constexpr uint16_t SplashDuration = 1200;
constexpr uint16_t FadeStepMs     = 16;
constexpr uint16_t BlinkPeriodMs  = 500;

// ============================================================================
// Helpers
// ============================================================================

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
    return ContentWidth;
}

inline constexpr int16_t contentHeight()
{
    return ContentHeight;
}

inline constexpr int16_t contentCenterX(int16_t width)
{
    return ContentLeft + ((ContentWidth - width) / 2);
}

inline constexpr int16_t contentCenterY(int16_t height)
{
    return ContentTop + ((ContentHeight - height) / 2);
}

} // namespace Layout

#endif
