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

void navigationSetActive(bool active);

void navigationSetGPS(bool gps);

void navigationSetTurn(TurnType turn);

void navigationSetRoad(const String &road);

void navigationSetDistance(uint32_t distance);

void navigationSetETA(uint16_t eta);

void navigationSetSpeed(uint16_t speed);

//
// ==========================================================
// GETTERS
// ==========================================================
//

bool navigationActive();

bool navigationHasGPS();

TurnType navigationTurn();

String navigationRoad();

uint32_t navigationDistance();

uint16_t navigationETA();

uint16_t navigationSpeed();

//
// ==========================================================
// INTERNAL
// ==========================================================
//

void navigationTouch();

#endif
