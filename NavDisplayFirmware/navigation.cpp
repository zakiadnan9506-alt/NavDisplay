#include "navigation.h"

//
// =====================================================
// INITIALIZATION
// =====================================================
//

void navigationBegin()
{
    resetNavigationData();
}

//
// =====================================================
// LOOP
// =====================================================
//

void navigationLoop()
{
    navigationUpdate();
}

//
// =====================================================
// UPDATE
// =====================================================
//

void navigationUpdate()
{
    if (!navigationActive())
    {
        return;
    }

    if (navigationTimedOut())
    {
        navigationStop();
    }
}

//
// =====================================================
// CONTROL
// =====================================================
//

void navigationStart()
{
    navData.active = true;
    navData.lastUpdate = millis();
}

void navigationStop()
{
    resetNavigationData();
}

void navigationRefresh()
{
    navData.lastUpdate = millis();
}

//
// =====================================================
// STATUS
// =====================================================
//

bool navigationActive()
{
    return navData.active;
}

bool navigationHasGPS()
{
    return navData.gpsValid;
}

bool navigationDataValid()
{
    return navigationActive() && navigationHasGPS();
}

bool navigationTimedOut()
{
    return navigationAge() > GPS_TIMEOUT_MS;
}

//
// =====================================================
// INFORMATION
// =====================================================
//

unsigned long navigationAge()
{
    return millis() - navData.lastUpdate;
}

uint32_t navigationDistance()
{
    return navData.distance;
}

uint16_t navigationSpeed()
{
    return navData.speed;
}

uint16_t navigationETA()
{
    return navData.eta;
}

String navigationRoad()
{
    return navData.roadName;
}

TurnType navigationTurn()
{
    return navData.turn;
}
