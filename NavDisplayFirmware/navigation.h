#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <Arduino.h>

#include "config.h"
#include "globals.h"

//
// =====================================================
// INITIALIZATION
// =====================================================
//

void navigationBegin();

//
// =====================================================
// UPDATE
// =====================================================
//

void navigationLoop();

void navigationUpdate();

//
// =====================================================
// CONTROL
// =====================================================
//

void navigationStart();

void navigationStop();

void navigationRefresh();

//
// =====================================================
// STATUS
// =====================================================
//

bool navigationActive();

bool navigationHasGPS();

bool navigationDataValid();

bool navigationTimedOut();

//
// =====================================================
// INFORMATION
// =====================================================
//

unsigned long navigationAge();

uint32_t navigationDistance();

uint16_t navigationSpeed();

uint16_t navigationETA();

String navigationRoad();

TurnType navigationTurn();

#endif
