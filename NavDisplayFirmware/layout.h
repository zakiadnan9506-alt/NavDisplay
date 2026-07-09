#ifndef LAYOUT_H
#define LAYOUT_H

#include <Arduino.h>

namespace Layout
{

// =====================================================
// SCREEN
// =====================================================

constexpr int16_t ScreenWidth  = 128;
constexpr int16_t ScreenHeight = 64;

// =====================================================
// TOP BAR
// =====================================================

constexpr int16_t TopBarHeight = 14;

// =====================================================
// STATUS ICON
// =====================================================

constexpr int16_t StatusMargin = 2;

constexpr int16_t GPSX = 2;
constexpr int16_t GPSY = 2;

constexpr int16_t BLEX = 16;
constexpr int16_t BLEY = 2;

constexpr int16_t BatteryX = 110;
constexpr int16_t BatteryY = 2;

constexpr int16_t ETAX = 72;
constexpr int16_t ETAY = 2;

// =====================================================
// TURN ICON
// =====================================================

constexpr int16_t TurnIconSize = 32;

constexpr int16_t TurnIconX = 2;

constexpr int16_t TurnIconY = 18;

// =====================================================
// DISTANCE
// =====================================================

constexpr int16_t DistanceX = 44;

constexpr int16_t DistanceY = 24;

// =====================================================
// ROAD
// =====================================================

constexpr int16_t RoadX = 2;

constexpr int16_t RoadY = 54;

// =====================================================
// SPEED
// =====================================================

constexpr int16_t SpeedX = 2;

constexpr int16_t SpeedY = 0;

}

#endif
