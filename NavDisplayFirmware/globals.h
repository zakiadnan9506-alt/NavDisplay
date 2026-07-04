#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

//
// ==========================================================
// TURN TYPE
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
    bool active = false;

    bool hasGPS = false;

    TurnType turn = TurnType::NONE;

    String road = "";

    uint32_t distance = 0;     // meter

    uint16_t eta = 0;          // menit

    uint16_t speed = 0;        // km/h

    uint32_t lastUpdate = 0;
};

//
// ==========================================================
// BATTERY DATA
// ==========================================================
//

struct BatteryData
{
    float voltage = 0.0f;

    uint8_t percentage = 0;

    bool charging = false;

    uint32_t lastUpdate = 0;
};

//
// ==========================================================
// SYSTEM STATUS
// ==========================================================
//

struct SystemStatus
{
    bool bleConnected = false;

    bool displayReady = false;

    bool parserReady = false;

    bool navigationReady = false;

    bool batteryReady = false;

    bool initialized = false;
};

//
// ==========================================================
// GLOBAL OBJECTS
// ==========================================================
//

extern NavigationData navData;

extern BatteryData batteryData;

extern SystemStatus systemStatus;

#endif
