// Placeho#include "DisplayManager.h"

DisplayManager Display;

DisplayManager::DisplayManager() :

display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
)

{

}

bool DisplayManager::begin()
{

    Wire.begin(
        OLED_SDA_PIN,
        OLED_SCL_PIN
    );

    if(
        !display.begin(
            SSD1306_SWITCHCAPVCC,
            OLED_I2C_ADDRESS
        )
    )
    {
        return false;
    }

    display.clearDisplay();

    display.display();

    return true;

}

void DisplayManager::splash()
{

    display.clearDisplay();

    display.setTextColor(
        SSD1306_WHITE
    );

    display.setTextSize(2);

    display.setCursor(10,18);

    display.println("NavDisplay");

    display.setTextSize(1);

    display.setCursor(24,46);

    display.println("ESP32-C3");

    display.display();

    delay(
        SPLASH_TIMEOUT_MS
    );

}

void DisplayManager::showDisconnected()
{

    display.clearDisplay();

    drawHeader();

    display.setTextSize(2);

    display.setCursor(0,20);

    display.println("Waiting");

    display.setTextSize(1);

    display.println();

    display.println("Bluetooth...");

    display.display();

}

void DisplayManager::showNavigation(
    const NavigationState &state
)

{

    display.clearDisplay();

    drawHeader();

    drawDirection(
        state.direction
    );

    drawDistance(
        state.distance
    );

    drawRoad(
        state.road
    );

    display.display();

}

void DisplayManager::update()
{

}

void DisplayManager::drawHeader()
{

    display.setTextSize(1);

    display.setCursor(0,0);

    display.println(
        PROJECT_NAME
    );

    display.drawLine(
        0,
        10,
        SCREEN_WIDTH,
        10,
        SSD1306_WHITE
    );

}

void DisplayManager::drawDistance(
    uint16_t distance
)

{

    display.setTextSize(2);

    display.setCursor(0,18);

    display.print(distance);

    display.print(" m");

}

void DisplayManager::drawRoad(
    const char *road
)

{

    display.setTextSize(1);

    display.setCursor(0,52);

    display.print(road);

}

void DisplayManager::drawDirection(
    Direction dir
)

{

    display.setTextSize(1);

    display.setCursor(90,18);

    switch(dir)
    {

        case Direction::TURN_LEFT:

            display.println("LEFT");

            break;

        case Direction::TURN_RIGHT:

            display.println("RIGHT");

            break;

        case Direction::STRAIGHT:

            display.println("GO");

            break;

        case Direction::UTURN:

            display.println("UTURN");

            break;

        case Direction::ROUNDABOUT:

            display.println("ROUND");

            break;

        case Direction::DESTINATION:

            display.println("ARRIVE");

            break;

        default:

            display.println("--");

            break;

    }

}lder - will be filled in subsequent steps.
