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
