/**************************************************************************
 *
 * NavDisplay Firmware v1.0
 *
 * File : display.cpp
 *
 **************************************************************************/

#include "display.h"

#include "icons.h"
#include "ble_server.h"
#include "navigation.h"
#include "parser.h"
#include "globals.h"

//
// ==========================================================
// DISPLAY OBJECT
// ==========================================================
//

Adafruit_SSD1306 display(128, 64, &Wire, -1);

//
// ==========================================================
// INTERNAL STATE
// ==========================================================
//

static DisplayState currentState = DisplayState::BOOT;

static uint32_t lastUpdate = 0;

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

bool displayBegin()
{
    Wire.begin(OLED_SDA_PIN, OLED_SCL_PIN);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
#ifdef DEBUG_SERIAL
        Serial.println("[DISPLAY] Init failed");
#endif
        return false;
    }

    display.clearDisplay();
    display.display();

    currentState = DisplayState::BOOT;

    return true;
}

//
// ==========================================================
// STATE MANAGEMENT
// ==========================================================
//

void displaySetState(DisplayState state)
{
    currentState = state;
}

DisplayState displayGetState()
{
    return currentState;
}
//
// ==========================================================
// DISPLAY UTILITIES
// ==========================================================
//

void displayClear()
{
    display.clearDisplay();
}

void displayRefresh()
{
    display.display();
}

void drawCenteredText(const String &text, int16_t y, uint8_t textSize)
{
    int16_t x1;
    int16_t y1;
    uint16_t w;
    uint16_t h;

    display.setTextSize(textSize);
    display.setTextColor(SSD1306_WHITE);

    display.getTextBounds(
        text,
        0,
        0,
        &x1,
        &y1,
        &w,
        &h);

    int16_t x = (SCREEN_WIDTH - w) / 2;

    if (x < 0)
    {
        x = 0;
    }

    display.setCursor(x, y);
    display.print(text);
}

void drawTitle(const String &title)
{
    display.drawFastHLine(
        0,
        14,
        SCREEN_WIDTH,
        SSD1306_WHITE);

    drawCenteredText(
        title,
        2,
        1);
}
//
// ==========================================================
// BASIC SCREENS
// ==========================================================
//

void drawSplashScreen()
{
    displayClear();

    drawCenteredText("NavDisplay", 18, 2);
    drawCenteredText("v1.0", 42, 1);

    displayRefresh();
}

void drawBluetoothWaiting()
{
    displayClear();

    drawTitle("Bluetooth");

    drawCenteredText("Waiting...", 28, 2);
    drawCenteredText("Connect Phone", 52, 1);

    displayRefresh();
}

void drawNoRouteScreen()
{
    displayClear();

    drawTitle("Navigation");

    drawCenteredText("No Route", 26, 2);
    drawCenteredText("Open Google Maps", 50, 1);

    displayRefresh();
}
//
// ==========================================================
// NAVIGATION WIDGETS
// ==========================================================
//

void drawTopBar(const String &title)
{
    display.fillRect(
        0,
        0,
        SCREEN_WIDTH,
        14,
        SSD1306_WHITE);

    display.setTextColor(SSD1306_BLACK);
    display.setTextSize(1);

    int16_t x1;
    int16_t y1;
    uint16_t w;
    uint16_t h;

    display.getTextBounds(
        title,
        0,
        0,
        &x1,
        &y1,
        &w,
        &h);

    int16_t x = (SCREEN_WIDTH - w) / 2;

    if (x < 0)
    {
        x = 0;
    }

    display.setCursor(x, 3);
    display.print(title);

    display.setTextColor(SSD1306_WHITE);
}

void drawDistance(const String &distance)
{
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(48, 22);
    display.print(distance);
}

void drawRoadName(const String &roadName)
{
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 50);
    display.print(roadName);
}

void drawETA(const String &eta)
{
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(92, 0);
    display.print(eta);
}

void drawSpeed(uint16_t speed)
{
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print(speed);
    display.print("km");
}
