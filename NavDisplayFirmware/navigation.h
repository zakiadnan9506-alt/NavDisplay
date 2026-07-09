#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <Arduino.h>

#include "config.h"
#include "globals.h"

namespace NavDisplay
{

// ============================================================================
// Lifecycle
// ============================================================================

void navigationBegin();
void navigationUpdate();
void navigationReset();

// ============================================================================
// Setters
// ============================================================================

void navigationSetActive(bool active);
void navigationSetGPS(bool gps);

void navigationSetRoad(const String& road);

void navigationSetDistance(uint32_t meter);
void navigationSetETA(uint16_t minute);
void navigationSetSpeed(uint16_t kmh);

void navigationSetTurn(TurnType turn);

// ============================================================================
// Getters
// ============================================================================

[[nodiscard]] bool navigationActive();
[[nodiscard]] bool navigationGPS();

[[nodiscard]] const String& navigationRoad();

[[nodiscard]] uint32_t navigationDistance();
[[nodiscard]] uint32_t navigationAge();

[[nodiscard]] uint16_t navigationETA();
[[nodiscard]] uint16_t navigationSpeed();

[[nodiscard]] TurnType navigationTurn();

// ============================================================================
// Internal
// ============================================================================

void navigationTouch();

} // namespace NavDisplay

#endif // NAVIGATION_H
