#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

//
// ==========================================================
// NAVDISPLAY FRAMEWORK v1.0
// Global Definitions
// ==========================================================
//

//
// ==========================================================
// TURN TYPE
// ==========================================================
//

enum class TurnType : uint8_t
{
    NONE = 0,

    // Basic
    STRAIGHT,
    CONTINUE,

    // Left
    SLIGHT_LEFT,
    LEFT,
    SHARP_LEFT,

    // Right
    SLIGHT_RIGHT,
    RIGHT,
    SHARP_RIGHT,

    // Keep
    KEEP_LEFT,
    KEEP_RIGHT,

    // Merge
    MERGE_LEFT,
    MERGE_RIGHT,

    // Fork
    FORK_LEFT,
    FORK_RIGHT,

    // Ramp
    RAMP_LEFT,
    RAMP_RIGHT,

    // Exit
    EXIT_LEFT,
    EXIT_RIGHT,

    // U-Turn
    UTURN_LEFT,
    UTURN_RIGHT,

    // Roundabout
    ROUNDABOUT_1,
    ROUNDABOUT_2,
    ROUNDABOUT_3,
    ROUNDABOUT_4,
    ROUNDABOUT_5,
    ROUNDABOUT_6,
    ROUNDABOUT_7,
    ROUNDABOUT_8,

    // Destination
    ARRIVE_LEFT,
    ARRIVE_RIGHT,
    DESTINATION,

    // Road Type
    FERRY,
    TUNNEL,
    HIGHWAY,
    TOLL_ROAD,

    // Status
    RECALCULATING,
    GPS_LOST,

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

    String road;

    uint32_t distance = 0;      // meter

    uint16_t eta = 0;           // minute

    uint16_t speed = 0;         // km/h

    uint32_t lastUpdate = 0;

    void reset()
    {
        active = false;
        hasGPS = false;
        turn = TurnType::NONE;
        road = "";
        distance = 0;
        eta = 0;
        speed = 0;
        lastUpdate = 0;
    }
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

    void reset()
    {
        voltage = 0.0f;
        percentage = 0;
        charging = false;
        lastUpdate = 0;
    }
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

    void reset()
    {
        bleConnected = false;
        displayReady = false;
        parserReady = false;
        navigationReady = false;
        batteryReady = false;
        initialized = false;
    }
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
