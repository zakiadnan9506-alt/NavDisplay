#ifndef BATTERY_H
#define BATTERY_H

#include <Arduino.h>

#include "config.h"
#include "globals.h"

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

void batteryBegin();

//
// ==========================================================
// UPDATE
// ==========================================================
//

void batteryUpdate();

//
// ==========================================================
// GETTERS
// ==========================================================
//

float batteryVoltage();

uint8_t batteryPercentage();

bool batteryCharging();

//
// ==========================================================
// INTERNAL
// ==========================================================
//

float batteryReadVoltage();

uint8_t batteryVoltageToPercent(float voltage);

#endif
