#ifndef ICONS_H
#define ICONS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "navigation.h"

//
// ==========================================================
// CONSTANTS
// ==========================================================
//

constexpr uint8_t ICON_SIZE = 18;

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
        // STRAIGHT
        //--------------------------------------------------

        case TurnType::STRAIGHT:

            gfx.drawLine(x + 9, y + 16, x + 9, y + 4, SSD1306_WHITE);

            gfx.fillTriangle(
                x + 9,
                y,
                x + 5,
                y + 6,
                x + 13,
                y + 6,
                SSD1306_WHITE);

            break;

        //--------------------------------------------------
        // LEFT
        //--------------------------------------------------

        case TurnType::LEFT:

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

        //--------------------------------------------------
        // RIGHT
        //--------------------------------------------------

        case TurnType::RIGHT:

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

        //--------------------------------------------------
        // UTURN LEFT
        //--------------------------------------------------

        case TurnType::UTURN_LEFT:

            gfx.drawCircle(x + 9, y + 9, 6, SSD1306_WHITE);

            gfx.fillTriangle(
                x,
                y + 9,
                x + 6,
                y + 5,
                x + 6,
                y + 13,
                SSD1306_WHITE);

            break;

        //--------------------------------------------------
        // UTURN RIGHT
        //--------------------------------------------------

        case TurnType::UTURN_RIGHT:

            gfx.drawCircle(x + 9, y + 9, 6, SSD1306_WHITE);

            gfx.fillTriangle(
                x + 18,
                y + 9,
                x + 12,
                y + 5,
                x + 12,
                y + 13,
                SSD1306_WHITE);

            break;

        //--------------------------------------------------
        // ROUNDABOUT
        //--------------------------------------------------

        case TurnType::ROUNDABOUT:

            gfx.drawCircle(x + 9, y + 9, 7, SSD1306_WHITE);

            gfx.fillCircle(x + 9, y + 9, 2, SSD1306_WHITE);

            break;

        //--------------------------------------------------
        // ARRIVE
        //--------------------------------------------------

        case TurnType::ARRIVE:

            gfx.drawRect(
                x + 3,
                y + 3,
                12,
                12,
                SSD1306_WHITE);

            gfx.fillRect(
                x + 5,
                y + 5,
                8,
                8,
                SSD1306_WHITE);

            break;

        //--------------------------------------------------
        // DEFAULT
        //--------------------------------------------------

        default:

            gfx.drawCircle(
                x + 9,
                y + 9,
                7,
                SSD1306_WHITE);

            break;
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
