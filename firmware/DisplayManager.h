// Placeholder - will be filled in subsequent steps.
#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"
#include "Types.h"

class DisplayManager
{
public:

    bool begin();

    void splash();

    void showWaiting();

    void showNavigation(const NavigationState &state);

    void update();

private:

    Adafruit_SSD1306 display =
        Adafruit_SSD1306(
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            &Wire,
            -1
        );

    void drawHeader(bool connected);

    void drawDirection(Direction direction);

};

extern DisplayManager oled;

#endif
