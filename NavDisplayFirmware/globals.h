#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <NimBLEDevice.h>

//
// =====================================================
// ENUM
// =====================================================
//

enum class BLEState : uint8_t
{
    DISCONNECTED = 0,
    ADVERTISING,
    CONNECTED
};

enum class TurnType : uint8_t
{
    NONE = 0,

    STRAIGHT,

    LEFT,
    RIGHT,

    SLIGHT_LEFT,
    SLIGHT_RIGHT,

    SHARP_LEFT,
    SHARP_RIGHT,

    UTURN_LEFT,
    UTURN_RIGHT,

    ROUNDABOUT,

    ARRIVE,

    UNKNOWN
};

//
// =====================================================
// NAVIGATION DATA
// =====================================================
//

struct NavigationData
{
    bool active;

    TurnType turn;

    String roadName;

    uint32_t distance;

    uint16_t speed;

    uint16_t eta;

    bool gpsValid;

    uint32_t lastUpdate;
};

//
// =====================================================
// SYSTEM STATUS
// =====================================================
//

struct SystemStatus
{
    BLEState bleState;

    bool bleConnected;

    bool displayReady;

    bool newData;
};

//
// =====================================================
// BATTERY
// =====================================================
//

struct BatteryStatus
{
    float voltage;

    uint8_t percent;

    bool charging;
};

//
// =====================================================
// GLOBAL VARIABLES
// =====================================================
//

extern NavigationData navData;

extern SystemStatus systemStatus;

extern BatteryStatus batteryStatus;

//
// =====================================================
// BLE OBJECTS
// =====================================================
//

extern NimBLEServer* bleServer;

extern NimBLEService* bleService;

extern NimBLECharacteristic* bleRxCharacteristic;

extern NimBLECharacteristic* bleTxCharacteristic;

//
// =====================================================
// TIMERS
// =====================================================
//

extern unsigned long lastDisplayRefresh;

extern unsigned long lastBLEActivity;

extern unsigned long lastBatteryRead;

//
// =====================================================
// FUNCTION PROTOTYPES
// =====================================================
//

void resetNavigationData();

void resetSystemStatus();

#endif
