#include "display.h"

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
    Wire.begin(OLED_SDA_PIN, OLED_SCL_PIN);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR))
    {
        systemStatus.displayReady = false;
        return false;
    }

    display.clearDisplay();

    display.setRotation(0);

    display.setTextColor(SSD1306_WHITE);

    display.setTextWrap(false);

    display.display();

    systemStatus.displayReady = true;

    drawSplashScreen();

    delay(1500);

    return true;
}

//
// =====================================================
// BASIC FUNCTIONS
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

    drawCenteredText(12, FW_NAME);

    display.setTextSize(1);

    drawCenteredText(40, "Firmware");

    drawCenteredText(54, FW_VERSION);

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

    drawCenteredText(20, "BOOTING");

    drawCenteredText(40, "Please Wait...");

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

    drawCenteredText(24, "NAV DISPLAY");

    drawCenteredText(44, "Waiting Navigation");

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

    drawCenteredText(20, "BLE");

    drawCenteredText(40, "Waiting...");

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

    drawCenteredText(20, "BLE Connected");

    drawCenteredText(40, "Ready");

    display.display();
}

//
// =====================================================
// NO GPS
// =====================================================
//

void drawNoGPSScreen()
{
    display.clearDisplay();

    drawStatusBar();

    drawCenteredText(24, "NO GPS");

    drawCenteredText(44, "Waiting Signal");

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

    display.setTextSize(2);

    display.setCursor(8, 18);
    display.print(navData.distance);

    display.setTextSize(1);

    display.print(" m");

    display.setCursor(8, 44);
    display.print(navData.roadName);

    drawTurnIcon(navData.turn, 96, 20);

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
        10,
        SCREEN_WIDTH,
        10,
        SSD1306_WHITE
    );

    display.setTextSize(1);

    display.setCursor(0, 0);

    if (systemStatus.bleConnected)
        display.print("BLE");
    else
        display.print("---");

    display.setCursor(46, 0);

    if (navData.gpsValid)
        display.print("GPS");
    else
        display.print("---");

    display.setCursor(94, 0);

    display.print(batteryStatus.percent);

    display.print("%");
}

//
// =====================================================
// CENTERED TEXT
// =====================================================
//

void drawCenteredText(
    int16_t y,
    const String& text,
    uint8_t textSize
)
{
    display.setTextSize(textSize);

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

    display.setCursor(x, y);

    display.print(text);
}

//
// =====================================================
// TITLE
// =====================================================
//

void drawTitle(const String& title)
{
    display.setTextSize(1);

    drawCenteredText(0, title);
}

//
// =====================================================
// TURN ICON
// =====================================================
//

void drawTurnIcon(
    TurnType turn,
    int16_t x,
    int16_t y
)
{
    display.drawRect(
        x,
        y,
        24,
        24,
        SSD1306_WHITE
    );

    display.setCursor(x + 8, y + 8);

    switch (turn)
    {
        case TurnType::LEFT:
            display.print("<");
            break;

        case TurnType::RIGHT:
            display.print(">");
            break;

        case TurnType::STRAIGHT:
            display.print("^");
            break;

        case TurnType::UTURN_LEFT:
            display.print("U");
            break;

        case TurnType::UTURN_RIGHT:
            display.print("U");
            break;

        default:
            display.print("?");
            break;
    }
}

//
// =====================================================
// UPDATE DISPLAY
// =====================================================
//

void updateDisplay()
{
    if (!systemStatus.displayReady)
        return;

    if (!systemStatus.bleConnected)
    {
        drawBLEWaitingScreen();
        return;
    }

    if (!navData.active)
    {
        drawBLEConnectedScreen();
        return;
    }

    if (!navData.gpsValid)
    {
        drawNoGPSScreen();
        return;
    }

    drawNavigationScreen();
}
