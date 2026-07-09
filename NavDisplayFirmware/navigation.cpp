#include "navigation.h"

namespace NavDisplay
{

// ============================================================================
// Lifecycle
// ============================================================================

void navigationBegin()
{
    navigationReset();
    systemStatus.navigationReady = true;
}

void navigationUpdate()
{
    if (!systemStatus.navigationReady)
    {
        return;
    }

    if (!navData.active)
    {
        return;
    }

    const uint32_t now = millis();

    if ((now - navData.lastUpdate) >= GPS_TIMEOUT_MS)
    {
        navigationReset();
    }
}

void navigationReset()
{
    navData.reset();
    navigationTouch();
}

// ============================================================================
// Internal
// ============================================================================

void navigationTouch()
{
    navData.lastUpdate = millis();
}

// ============================================================================
// Setters
// ============================================================================

void navigationSetActive(bool active)
{
    navData.active = active;
    navigationTouch();
}

void navigationSetGPS(bool gps)
{
    navData.hasGPS = gps;
    navigationTouch();
}

void navigationSetRoad(const String& road)
{
    navData.road = road;

    if (navData.road.length() > MAX_ROAD_LENGTH)
    {
        navData.road.remove(MAX_ROAD_LENGTH);
    }

    navigationTouch();
}

void navigationSetDistance(uint32_t meter)
{
    navData.distance = meter;
    navigationTouch();
}

void navigationSetETA(uint16_t minute)
{
    navData.eta = minute;
    navigationTouch();
}

void navigationSetSpeed(uint16_t kmh)
{
    navData.speed = kmh;
    navigationTouch();
}

void navigationSetTurn(TurnType turn)
{
    navData.turn = turn;
    navigationTouch();
}

// ============================================================================
// Getters
// ============================================================================

bool navigationActive()
{
    return navData.active;
}

bool navigationGPS()
{
    return navData.hasGPS;
}

const String& navigationRoad()
{
    return navData.road;
}

uint32_t navigationDistance()
{
    return navData.distance;
}

uint32_t navigationAge()
{
    return millis() - navData.lastUpdate;
}

uint16_t navigationETA()
{
    return navData.eta;
}

uint16_t navigationSpeed()
{
    return navData.speed;
}

TurnType navigationTurn()
{
    return navData.turn;
}

} // namespace NavDisplay
