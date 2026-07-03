/**************************************************************************
 *
 *  NavDisplay Firmware v1.0
 *
 *  File        : display.cpp
 *  Description : OLED Display Module
 *
 **************************************************************************/

#include "display.h"

#include "navigation.h"

//
// =====================================================
// OLED OBJECT
// =====================================================
//

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

//
// =====================================================
// DISPLAY INITIALIZATION
// =====================================================
//

bool displayBegin()
{
    Wire.begin(
        OLED_SDA_PIN,
        OLED_SCL_PIN
    );

    bool ok = display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_I2C_ADDR
    );

    if (!ok)
    {
        systemStatus.displayReady = false;
        return false;
    }

    display.clearDisplay();

    display.setRotation(0);

    display.setTextColor(SSD1306_WHITE);

    display.setTextWrap(false);

    display.cp437(true);

    display.display();

    systemStatus.displayReady = true;

    drawSplashScreen();

    delay(1500);

    return true;
}

//
// =====================================================
// BASIC DISPLAY
// =====================================================
//

void displayClear()
{
    display.clearDisplay();
}

void displayUpdate()
{
    display.display();
}

//
// =====================================================
// SPLASH SCREEN
// =====================================================
//

void drawSplashScreen()
{
    display.clearDisplay();

    display.setTextSize(2);

    drawCenteredText(
        8,
        FW_NAME,
        2
    );

    display.setTextSize(1);

    drawCenteredText(
        34,
        "Navigation Display"
    );

    drawCenteredText(
        48,
        "Firmware"
    );

    drawCenteredText(
        58,
        FW_VERSION
    );

    display.display();
}

//
// =====================================================
// BOOT SCREEN
// =====================================================
//

void drawBootScreen()
{
    display.clearDisplay();

    drawCenteredText(
        20,
        "Initializing..."
    );

    drawCenteredText(
        40,
        "Please Wait"
    );

    display.display();
}

//
// =====================================================
// IDLE SCREEN
// =====================================================
//

void drawIdleScreen()
{
    display.clearDisplay();

    drawStatusBar();

    drawCenteredText(
        22,
        "NavDisplay"
    );

    drawCenteredText(
        40,
        "Waiting Navigation"
    );

    display.display();
}

//
// =====================================================
// BLE WAITING
// =====================================================
//

void drawBLEWaitingScreen()
{
    display.clearDisplay();

    drawStatusBar();

    drawCenteredText(
        22,
        "Bluetooth"
    );

    drawCenteredText(
        40,
        "Waiting Device..."
    );

    display.display();
}

//
// =====================================================
// BLE CONNECTED
// =====================================================
//

void drawBLEConnectedScreen()
{
    display.clearDisplay();

    drawStatusBar();

    drawCenteredText(
        22,
        "Bluetooth"

    );

    drawCenteredText(
        40,
        "Connected"
    );

    display.display();
}
//
// =====================================================
// NO GPS SCREEN
// =====================================================
//

void drawNoGPSScreen()
{
    display.clearDisplay();

    drawStatusBar();

    drawCenteredText(
        22,
        "GPS"
    );

    drawCenteredText(
        40,
        "Waiting Signal..."
    );

    display.display();
}

//
// =====================================================
// NAVIGATION SCREEN
// =====================================================
//

void drawNavigationScreen()
{
    display.clearDisplay();

    drawStatusBar();

    //
    // Turn Icon
    //
    drawTurnIcon(
        navigationTurn(),
        4,
        16
    );

    //
    // Distance
    //
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);

    display.setCursor(40, 18);
    display.print(navigationDistance());
    display.print("m");

    //
    // Road Name
    //
    display.setTextSize(1);

    display.setCursor(0, 44);

    String road = navigationRoad();

    if (road.length() > 21)
    {
        road = road.substring(0, 21);
    }

    display.print(road);

    //
    // ETA
    //
    display.setCursor(0, 56);
    display.print("ETA ");
    display.print(navigationETA());
    display.print("m");

    //
    // Speed
    //
    display.setCursor(74, 56);
    display.print(navigationSpeed());
    display.print("km/h");

    display.display();
}

//
// =====================================================
// STATUS BAR
// =====================================================
//

void drawStatusBar()
{
    display.drawLine(
        0,
        11,
        SCREEN_WIDTH,
        11,
        SSD1306_WHITE
    );

    //
    // BLE
    //
    display.setTextSize(1);
    display.setCursor(0, 1);

    if (systemStatus.bleConnected)
    {
        display.print("BLE");
    }
    else
    {
        display.print("---");
    }

    //
    // GPS
    //
    display.setCursor(48, 1);

    if (navigationHasGPS())
    {
        display.print("GPS");
    }
    else
    {
        display.print("---");
    }

    //
    // Battery
    //
    display.setCursor(92, 1);

    display.print("BAT");
}

//
// =====================================================
// TITLE
// =====================================================
//

void drawTitle(const String &title)
{
    display.setTextSize(1);

    drawCenteredText(
        0,
        title
    );
}

//
// =====================================================
// CENTER TEXT
// =====================================================
//

void drawCenteredText(
    int y,
    const String &text,
    uint8_t size
)
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

    int16_t x = (SCREEN_WIDTH - w) / 2;

    if (x < 0)
    {
        x = 0;
    }

    display.setCursor(
        x,
        y
    );

    display.print(text);
}
