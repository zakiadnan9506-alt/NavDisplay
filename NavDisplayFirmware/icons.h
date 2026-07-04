#ifndef ICONS_H
#define ICONS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "navigation.h"

//
// ==========================================================
// CONSTANTS
// ==========================================================
//

constexpr uint8_t ICON_SIZE = 18;
constexpr uint8_t ICON_CENTER = ICON_SIZE / 2;

//
// ==========================================================
// TURN ICON
// ==========================================================
//

inline void drawTurnIcon(
    Adafruit_GFX& gfx,
    TurnType turn,
    int16_t x,
    int16_t y)
{
    switch (turn)
    {
        //--------------------------------------------------
        // NONE
        //--------------------------------------------------
        case TurnType::NONE:
        {
            gfx.drawCircle(x + ICON_CENTER, y + 9, 2, SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // STRAIGHT
        //--------------------------------------------------
        case TurnType::STRAIGHT:
        {
            gfx.drawLine(x + ICON_CENTER, y + 16, x + ICON_CENTER, y + 4, SSD1306_WHITE);

            gfx.fillTriangle(
                x + ICON_CENTER, y,
                x + 5, y + 6,
                x + 13, y + 6,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // SLIGHT LEFT
        //--------------------------------------------------
        case TurnType::SLIGHT_LEFT:
        {
            gfx.drawLine(x + 13, y + 15, x + 8, y + 10, SSD1306_WHITE);
            gfx.drawLine(x + 8, y + 10, x + 8, y + 4, SSD1306_WHITE);

            gfx.fillTriangle(
                x + 4, y + 5,
                x + 8, y + 1,
                x + ICON_CENTER, y + 8,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // LEFT
        //--------------------------------------------------
        case TurnType::LEFT:
        {
            gfx.drawLine(x + 15, y + 15, x + 6, y + 15, SSD1306_WHITE);
            gfx.drawLine(x + 6, y + 15, x + 6, y + 4, SSD1306_WHITE);

            gfx.fillTriangle(
                x,
                y + 4,
                x + 6,
                y,
                x + 6,
                y + 8,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // SHARP LEFT
        //--------------------------------------------------
        case TurnType::SHARP_LEFT:
        {
            gfx.drawLine(x + 15, y + 16, x + 7, y + 8, SSD1306_WHITE);
            gfx.drawLine(x + 7, y + 8, x + 7, y + 2, SSD1306_WHITE);

            gfx.fillTriangle(
                x + 2,
                y + 2,
                x + 7,
                y,
                x + 8,
                y + 6,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // SLIGHT RIGHT
        //--------------------------------------------------
        case TurnType::SLIGHT_RIGHT:
        {
            gfx.drawLine(x + 5, y + 15, x + 10, y + 10, SSD1306_WHITE);
            gfx.drawLine(x + 10, y + 10, x + 10, y + 4, SSD1306_WHITE);

            gfx.fillTriangle(
                x + 14,
                y + 5,
                x + 10,
                y + 1,
                x + ICON_CENTER,
                y + 8,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // RIGHT
        //--------------------------------------------------
        case TurnType::RIGHT:
        {
            gfx.drawLine(x + 2, y + 15, x + 11, y + 15, SSD1306_WHITE);
            gfx.drawLine(x + 11, y + 15, x + 11, y + 4, SSD1306_WHITE);

            gfx.fillTriangle(
                x + 17,
                y + 4,
                x + 11,
                y,
                x + 11,
                y + 8,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // SHARP RIGHT
        //--------------------------------------------------
        case TurnType::SHARP_RIGHT:
        {
            gfx.drawLine(x + 3, y + 16, x + 11, y + 8, SSD1306_WHITE);
            gfx.drawLine(x + 11, y + 8, x + 11, y + 2, SSD1306_WHITE);

            gfx.fillTriangle(
                x + 16,
                y + 2,
                x + 11,
                y,
                x + 10,
                y + 6,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // UTURN LEFT
        //--------------------------------------------------
        case TurnType::UTURN_LEFT:
        {
            gfx.drawCircle(x + ICON_CENTER, y + 9, 6, SSD1306_WHITE);

            gfx.fillTriangle(
                x,
                y + 9,
                x + 6,
                y + 5,
                x + 6,
                y + 13,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // UTURN RIGHT
        //--------------------------------------------------
        case TurnType::UTURN_RIGHT:
        {
            gfx.drawCircle(x + ICON_CENTER, y + 9, 6, SSD1306_WHITE);

            gfx.fillTriangle(
                x + 18,
                y + 9,
                x + 12,
                y + 5,
                x + 12,
                y + 13,
                SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // ROUNDABOUT
        //--------------------------------------------------
        case TurnType::ROUNDABOUT:
        {
            gfx.drawCircle(x + ICON_CENTER, y + 9, 7, SSD1306_WHITE);
            gfx.fillCircle(x + ICON_CENTER, y + 9, 2, SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // ARRIVE
        //--------------------------------------------------
        case TurnType::ARRIVE:
        {
            gfx.drawRect(x + 3, y + 3, 12, 12, SSD1306_WHITE);
            gfx.fillRect(x + 5, y + 5, 8, 8, SSD1306_WHITE);
            break;
        }

        //--------------------------------------------------
        // UNKNOWN
        //--------------------------------------------------
        case TurnType::UNKNOWN:
        default:
        {
            gfx.drawCircle(x + ICON_CENTER, y + 9, 7, SSD1306_WHITE);
            gfx.drawLine(x + ICON_CENTER, y + 5, x + 9, y + 10, SSD1306_WHITE);
            gfx.drawPixel(x + ICON_CENTER, y + 13, SSD1306_WHITE);
            break;
        }
    }
}

//
// ==========================================================
// BLE ICON
// ==========================================================
//

inline void drawBLEIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    bool connected)
{
    gfx.drawLine(x + 4, y, x + 4, y + 14, SSD1306_WHITE);

    gfx.drawLine(x + 4, y, x + 8, y + 4, SSD1306_WHITE);
    gfx.drawLine(x + 4, y + 14, x + 8, y + 10, SSD1306_WHITE);

    gfx.drawLine(x + 4, y + 7, x + 8, y + 4, SSD1306_WHITE);
    gfx.drawLine(x + 4, y + 7, x + 8, y + 10, SSD1306_WHITE);

    if (connected)
    {
        gfx.fillCircle(x + 12, y + 12, 2, SSD1306_WHITE);
    }
}

//
// ==========================================================
// GPS ICON
// ==========================================================
//

inline void drawGPSIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    bool gps)
{
    gfx.drawCircle(x + 6, y + 6, 5, SSD1306_WHITE);

    gfx.drawPixel(x + 6, y + 6, SSD1306_WHITE);

    if (gps)
    {
        gfx.fillCircle(x + 6, y + 6, 2, SSD1306_WHITE);
    }
}

//
// ==========================================================
// BATTERY ICON
// ==========================================================
//

inline void drawBatteryIcon(
    Adafruit_GFX& gfx,
    int16_t x,
    int16_t y,
    uint8_t percent)
{
    gfx.drawRect(x, y, 18, 8, SSD1306_WHITE);

    gfx.drawRect(x + 18, y + 2, 2, 4, SSD1306_WHITE);

    percent = constrain(percent, 0, 100);

    uint8_t fill =
        map(percent, 0, 100, 0, 16);

    if (fill > 0)
    {
        gfx.fillRect(
            x + 1,
            y + 1,
            fill,
            6,
            SSD1306_WHITE);
    }
}

#endif
