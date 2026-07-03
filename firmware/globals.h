#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <NimBLEDevice.h>

//
// ==========================================================
// BLE STATUS
// ==========================================================
//

enum class BLEState : uint8_t
{
    DISCONNECTED = 0,
    ADVERTISING,
    CONNECTED
};

//
// ==========================================================
// NAVIGATION TURN TYPE
// ==========================================================
//

enum class TurnType : uint8_t
{
    NONE = 0,

    STRAIGHT,

    SLIGHT_LEFT,
    LEFT,
    SHARP_LEFT,

    SLIGHT_RIGHT,
    RIGHT,
    SHARP_RIGHT,

    UTURN_LEFT,
    UTURN_RIGHT,

    ROUNDABOUT,

    ARRIVE,

    UNKNOWN
};

//
// ==========================================================
// NAVIGATION DATA
// ==========================================================
//

struct NavigationData
{
    String roadName;

    TurnType turn;

    uint32_t distanceMeters;

    uint16_t speedKmh;

    uint16_t etaMinutes;

    bool gpsAvailable;
    bool navigating;
};

//
// ==========================================================
// SYSTEM STATUS
// ==========================================================
//

struct SystemStatus
{
    BLEState bleState;

    bool displayReady;

    bool oledFound;

    bool bleConnected;

    bool newNavigationData;
};

//
// ==========================================================
// BATTERY STATUS
// ==========================================================
//

struct BatteryStatus
{
    float voltage;

    uint8_t percentage;

    bool charging;
};

//
// ==========================================================
// GLOBAL VARIABLES
// ==========================================================
//

extern NavigationData navData;

extern SystemStatus systemStatus;

extern BatteryStatus batteryStatus;

//
// ==========================================================
// BLE OBJECTS
// ==========================================================
//

extern NimBLEServer* bleServer;

extern NimBLEService* bleService;

extern NimBLECharacteristic* bleRxCharacteristic;

extern NimBLECharacteristic* bleTxCharacteristic;

//
// ==========================================================
// TIMERS
// ==========================================================
//

extern uint32_t lastDisplayUpdate;

extern uint32_t lastBLEActivity;

extern uint32_t lastBatteryUpdate;

//
// ==========================================================
// FUNCTION PROTOTYPES
// ==========================================================
//

void resetNavigationData();
void resetSystemStatus();

#endif
