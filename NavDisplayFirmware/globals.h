#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

namespace NavDisplay
{

// ============================================================================
// Turn Types
// ============================================================================

enum class TurnType : uint8_t
{
    NONE = 0,

    STRAIGHT,
    CONTINUE,

    SLIGHT_LEFT,
    LEFT,
    SHARP_LEFT,

    SLIGHT_RIGHT,
    RIGHT,
    SHARP_RIGHT,

    KEEP_LEFT,
    KEEP_RIGHT,

    MERGE_LEFT,
    MERGE_RIGHT,

    FORK_LEFT,
    FORK_RIGHT,

    RAMP_LEFT,
    RAMP_RIGHT,

    EXIT_LEFT,
    EXIT_RIGHT,

    UTURN_LEFT,
    UTURN_RIGHT,

    ROUNDABOUT_1,
    ROUNDABOUT_2,
    ROUNDABOUT_3,
    ROUNDABOUT_4,
    ROUNDABOUT_5,
    ROUNDABOUT_6,
    ROUNDABOUT_7,
    ROUNDABOUT_8,

    ARRIVE_LEFT,
    ARRIVE_RIGHT,
    DESTINATION,

    FERRY,
    TUNNEL,
    HIGHWAY,
    TOLL_ROAD,

    RECALCULATING,
    GPS_LOST,

    UNKNOWN
};

// ============================================================================
// Navigation Data
// ============================================================================

struct NavigationData
{
    bool active = false;
    bool hasGPS = false;

    TurnType turn = TurnType::NONE;

    String road;

    uint32_t distance = 0;
    uint16_t eta = 0;
    uint16_t speed = 0;

    uint32_t lastUpdate = 0;

    constexpr NavigationData() = default;

    void reset() noexcept
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

    bool valid() const noexcept
    {
        return active;
    }
};

// ============================================================================
// Battery Data
// ============================================================================

struct BatteryData
{
    float voltage = 0.0f;
    uint8_t percentage = 0;
    bool charging = false;

    uint32_t lastUpdate = 0;

    constexpr BatteryData() = default;

    void reset() noexcept
    {
        voltage = 0.0f;
        percentage = 0;
        charging = false;
        lastUpdate = 0;
    }
};

// ============================================================================
// System Status
// ============================================================================

struct SystemStatus
{
    bool bleConnected = false;
    bool displayReady = false;
    bool parserReady = false;
    bool navigationReady = false;
    bool batteryReady = false;
    bool initialized = false;

    constexpr SystemStatus() = default;

    void reset() noexcept
    {
        bleConnected = false;
        displayReady = false;
        parserReady = false;
        navigationReady = false;
        batteryReady = false;
        initialized = false;
    }
};

// ============================================================================
// Global Objects
// ============================================================================

extern NavigationData navData;
extern BatteryData batteryData;
extern SystemStatus systemStatus;

} // namespace NavDisplay

#endif
