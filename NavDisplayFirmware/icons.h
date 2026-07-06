#ifndef ICONS_H
#define ICONS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "navigation.h"

constexpr uint8_t NAV_ICON_SIZE = 48;

void drawTurnIcon(
    Adafruit_GFX& display,
    TurnType turn,
    int16_t x,
    int16_t y);

void drawBLEIcon(
    Adafruit_GFX& display,
    int16_t x,
    int16_t y,
    bool connected);

void drawGPSIcon(
    Adafruit_GFX& display,
    int16_t x,
    int16_t y,
    bool gps);

void drawBatteryIcon(
    Adafruit_GFX& display,
    int16_t x,
    int16_t y,
    uint8_t percent);

#endif
