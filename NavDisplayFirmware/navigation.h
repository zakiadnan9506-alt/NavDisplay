#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <Arduino.h>

#include "config.h"
#include "globals.h"

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

void navigationBegin();

//
// ==========================================================
// UPDATE
// ==========================================================
//

void navigationUpdate();

//
// ==========================================================
// RESET
// ==========================================================
//

void navigationReset();

//
// ==========================================================
// SETTERS
// ==========================================================
//

void navigationBegin();

void navigationUpdate();

void navigationReset();

void navigationSetActive(bool active);

void navigationSetGPS(bool gps);

void navigationSetRoad(const String &road);

void navigationSetDistance(uint32_t meter);

void navigationSetETA(uint16_t minute);

void navigationSetSpeed(uint16_t kmh);

void navigationSetTurn(TurnType turn);

//
// ==========================================================
// GETTERS
// ==========================================================
//
bool navigationActive();

bool navigationGPS();

const String& navigationRoad();

uint32_t navigationDistance();

uint16_t navigationETA();

uint16_t navigationSpeed();

TurnType navigationTurn();
//
// ==========================================================
// INTERNAL
// ==========================================================
//

void navigationTouch();

#endif
