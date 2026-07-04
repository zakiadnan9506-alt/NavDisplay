#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"
#include "globals.h"
#include "navigation.h"

//
// =====================================================
// OLED OBJECT
// =====================================================
//

extern Adafruit_SSD1306 display;

//
// =====================================================
// INITIALIZATION
// =====================================================
//

bool displayBegin();

//
// =====================================================
// BASIC FUNCTIONS
// =====================================================
//

void displayClear();

void displayUpdate();

//
// =====================================================
// SCREEN FUNCTIONS
// =====================================================
//

void drawSplashScreen();

void drawBootScreen();

void drawIdleScreen();

void drawBLEWaitingScreen();

void drawBLEConnectedScreen();

void drawNavigationScreen();

void drawNoGPSScreen();

//
// =====================================================
// STATUS BAR
// =====================================================
//

void drawStatusBar();

//
// =====================================================
// TEXT HELPERS
// =====================================================
//

void drawCenteredText(
    int16_t y,
    const String& text,
    uint8_t textSize = 1
);

void drawTitle(
    const String& title
);

//
// =====================================================
// ICON HELPERS
// =====================================================
//

void drawTurnIcon(
    TurnType turn,
    int16_t x,
    int16_t y
);

void drawBLEIcon(
    int16_t x,
    int16_t y
);

void drawGPSIcon(
    int16_t x,
    int16_t y
);

void drawBatteryIcon(
    int16_t x,
    int16_t y,
    uint8_t percent
);

//
// =====================================================
// DRAW HELPERS
// =====================================================
//

void drawHorizontalSeparator(
    int16_t y
);

//
// =====================================================
// UPDATE
// =====================================================
//

void updateDisplay();

#endif
