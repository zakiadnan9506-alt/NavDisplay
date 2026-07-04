/**************************************************************************
 *
 * NavDisplay Firmware v1.0
 *
 * File : display.cpp
 *
 **************************************************************************/

#include "display.h"

#include "battery.h"
#include "navigation.h"
#include "utils.h"
#include "icons.h"

//
// ==========================================================
// OLED OBJECT
// ==========================================================
//

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

//
// ==========================================================
// DISPLAY STATE
// ==========================================================
//

static DisplayState currentState = DisplayState::BOOT;

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

bool displayBegin()
{
    Wire.begin(OLED_SDA_PIN, OLED_SCL_PIN);

    if (!display.begin(
            SSD1306_SWITCHCAPVCC,
            OLED_I2C_ADDR))
    {
        return false;
    }

    display.clearDisplay();

    display.setRotation(0);

    display.setTextColor(SSD1306_WHITE);

    display.setTextWrap(false);

    display.display();

    systemStatus.displayReady = true;

    currentState = DisplayState::BOOT;

    return true;
}

//
// ==========================================================
// DISPLAY STATE
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
// BASIC
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

//
// ==========================================================
// TITLE
// ==========================================================
//

void drawTitle(const String &title)
{
    display.setTextSize(1);

    display.setCursor(0,0);

    display.print(title);

    display.drawLine(
        0,
        10,
        SCREEN_WIDTH-1,
        10,
        SSD1306_WHITE
    );
}

//
// ==========================================================
// CENTER TEXT
// ==========================================================
//

void drawCenteredText(
    int16_t y,
    const String &text,
    uint8_t size)
{
    display.setTextSize(size);

    int16_t x1;
    int16_t y1;

    uint16_t w;
    uint16_t h;

    display.getTextBounds(
        text,
        0,
        0,
        &x1,
        &y1,
        &w,
        &h
    );

    int16_t x =
        (SCREEN_WIDTH - w) / 2;

    display.setCursor(x,y);

    display.print(text);
}
//
// ==========================================================
// BOOT SCREEN
// ==========================================================
//

void drawBootScreen()
{
    displayClear();

    drawCenteredText(10, FW_NAME, 2);

    drawCenteredText(34, FW_VERSION, 1);

    display.setCursor(34, 52);
    display.print("Initializing...");

    displayRefresh();
}

//
// ==========================================================
// WAIT BLE
// ==========================================================
//

void drawWaitingBLE()
{
    displayClear();

    drawTitle("Bluetooth");

    drawCenteredText(22, "Waiting iPhone", 1);

    drawCenteredText(40, BLE_DEVICE_NAME, 1);

    displayRefresh();
}

//
// ==========================================================
// CONNECTED
// ==========================================================
//

void drawConnected()
{
    displayClear();

    drawTitle("Bluetooth");

    drawCenteredText(20, "Connected", 2);

    drawCenteredText(46, "Waiting GPS...", 1);

    displayRefresh();
}

//
// ==========================================================
// WAIT GPS
// ==========================================================
//

void drawWaitingGPS()
{
    displayClear();

    drawTitle("Navigation");

    drawCenteredText(20, "Searching", 2);

    drawCenteredText(42, "GPS Signal", 1);

    displayRefresh();
}
