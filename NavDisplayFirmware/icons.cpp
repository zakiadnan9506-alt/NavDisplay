/**************************************************************************
 *
 * NavDisplay Framework v1.0
 *
 * File : icons.cpp
 *
 **************************************************************************/

#include "icons.h"

#include <math.h>

//
// ==========================================================
// INTERNAL PRIMITIVES
// ==========================================================
//

namespace
{

constexpr int16_t ICON_HALF = NAV_ICON_SIZE / 2;

//
// ----------------------------------------------------------
// Draw Arrow Head
// ----------------------------------------------------------
//

static void drawArrowHead(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y,
    int8_t dx,
    int8_t dy)
{
    const int16_t s = 5;

    if (dx > 0)
    {
        d.drawLine(x, y, x - s, y - s, SSD1306_WHITE);
        d.drawLine(x, y, x - s, y + s, SSD1306_WHITE);
    }
    else if (dx < 0)
    {
        d.drawLine(x, y, x + s, y - s, SSD1306_WHITE);
        d.drawLine(x, y, x + s, y + s, SSD1306_WHITE);
    }
    else if (dy > 0)
    {
        d.drawLine(x, y, x - s, y - s, SSD1306_WHITE);
        d.drawLine(x, y, x + s, y - s, SSD1306_WHITE);
    }
    else
    {
        d.drawLine(x, y, x - s, y + s, SSD1306_WHITE);
        d.drawLine(x, y, x + s, y + s, SSD1306_WHITE);
    }
}

//
// ----------------------------------------------------------
// Vertical Arrow
// ----------------------------------------------------------
//

static void drawArrowUp(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawLine(
        x,
        y + 30,
        x,
        y + 8,
        SSD1306_WHITE);

    drawArrowHead(
        d,
        x,
        y + 4,
        0,
        -1);
}

//
// ----------------------------------------------------------
// Down Arrow
// ----------------------------------------------------------
//

static void drawArrowDown(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawLine(
        x,
        y + 4,
        x,
        y + 28,
        SSD1306_WHITE);

    drawArrowHead(
        d,
        x,
        y + 32,
        0,
        1);
}

//
// ----------------------------------------------------------
// Left Arrow
// ----------------------------------------------------------
//

static void drawArrowLeft(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawLine(
        x + 30,
        y + 16,
        x + 8,
        y + 16,
        SSD1306_WHITE);

    drawArrowHead(
        d,
        x + 4,
        y + 16,
        -1,
        0);
}

//
// ----------------------------------------------------------
// Right Arrow
// ----------------------------------------------------------
//

static void drawArrowRight(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawLine(
        x + 4,
        y + 16,
        x + 28,
        y + 16,
        SSD1306_WHITE);

    drawArrowHead(
        d,
        x + 32,
        y + 16,
        1,
        0);
}

//
// ----------------------------------------------------------
// Curve Left
// ----------------------------------------------------------
//

static void drawCurveLeft(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawLine(
        x + 16,
        y + 30,
        x + 16,
        y + 16,
        SSD1306_WHITE);

    d.drawLine(
        x + 16,
        y + 16,
        x + 6,
        y + 16,
        SSD1306_WHITE);

    drawArrowHead(
        d,
        x + 4,
        y + 16,
        -1,
        0);
}

//
// ----------------------------------------------------------
// Curve Right
// ----------------------------------------------------------
//

static void drawCurveRight(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawLine(
        x + 16,
        y + 30,
        x + 16,
        y + 16,
        SSD1306_WHITE);

    d.drawLine(
        x + 16,
        y + 16,
        x + 26,
        y + 16,
        SSD1306_WHITE);

    drawArrowHead(
        d,
        x + 28,
        y + 16,
        1,
        0);
}

//
// ----------------------------------------------------------
// U-Turn Left
// ----------------------------------------------------------
//

static void drawUTurnLeft(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawCircle(
        x + 16,
        y + 16,
        10,
        SSD1306_WHITE);

    drawArrowHead(
        d,
        x + 4,
        y + 16,
        -1,
        0);
}

//
// ----------------------------------------------------------
// U-Turn Right
// ----------------------------------------------------------
//

static void drawUTurnRight(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawCircle(
        x + 16,
        y + 16,
        10,
        SSD1306_WHITE);

    drawArrowHead(
        d,
        x + 28,
        y + 16,
        1,
        0);
}

//
// ----------------------------------------------------------
// Destination Flag
// ----------------------------------------------------------
//

static void drawFlag(
    Adafruit_GFX& d,
    int16_t x,
    int16_t y)
{
    d.drawLine(
        x + 8,
        y + 4,
        x + 8,
        y + 28,
        SSD1306_WHITE);

    d.fillTriangle(
        x + 8,
        y + 4,
        x + 24,
        y + 10,
        x + 8,
        y + 16,
        SSD1306_WHITE);
}

} // namespace
