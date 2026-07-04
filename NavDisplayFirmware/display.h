#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"
#include "globals.h"

//
// ==========================================================
// DISPLAY OBJECT
// ==========================================================
//

extern Adafruit_SSD1306 display;

//
// ==========================================================
// DISPLAY STATE
// ==========================================================
//

enum class DisplayState : uint8_t
{
    BOOT = 0,

    WAIT_BLE,

    CONNECTED,

    WAIT_GPS,

    NAVIGATION,

    IDLE
};

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

bool displayBegin();

//
// ==========================================================
// UPDATE
// ==========================================================
//

void updateDisplay();

//
// ==========================================================
// STATE
// ==========================================================
//

void displaySetState(DisplayState state);

DisplayState displayGetState();

//
// ==========================================================
// SCREENS
// ==========================================================
//

void drawBootScreen();

void drawWaitingBLE();

void drawConnected();

void drawWaitingGPS();

void drawNavigation();

void drawIdleScreen();

//
// ==========================================================
// HELPERS
// ==========================================================
//

void drawStatusBar();

void drawCenteredText(
    int16_t y,
    const String &text,
    uint8_t size = 1
);

void drawTitle(
    const String &title
);

void displayClear();

void displayRefresh();

#endif
