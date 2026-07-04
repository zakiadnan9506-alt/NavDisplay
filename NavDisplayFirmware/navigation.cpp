/**************************************************************************
 *
 *  NavDisplay Firmware v1.0
 *
 *  File        : navigation.cpp
 *  Description : Navigation Manager
 *
 **************************************************************************/

#include "navigation.h"

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

void navigationBegin()
{
    navigationReset();

    systemStatus.navigationReady = true;
}

//
// ==========================================================
// UPDATE
// ==========================================================
//

void navigationUpdate()
{
    if (!systemStatus.navigationReady)
    {
        return;
    }

    // Timeout navigation apabila tidak ada data baru
    if (navData.active)
    {
        if ((millis() - navData.lastUpdate) > GPS_TIMEOUT_MS)
        {
            navigationReset();
        }
    }
}

//
// ==========================================================
// RESET
// ==========================================================
//

void navigationReset()
{
    navData.active = false;

    navData.hasGPS = false;

    navData.turn = TurnType::NONE;

    navData.road = "";

    navData.distance = 0;

    navData.eta = 0;

    navData.speed = 0;

    navData.lastUpdate = millis();
}

//
// ==========================================================
// INTERNAL
// ==========================================================
//

void navigationTouch()
{
    navData.lastUpdate = millis();
}

//
// ==========================================================
// SETTERS
// ==========================================================
//

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

void navigationSetTurn(TurnType turn)
{
    navData.turn = turn;

    navigationTouch();
}

void navigationSetRoad(const String &road)
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

void navigationSetETA(uint16_t eta)
{
    navData.eta = eta;

    navigationTouch();
}

void navigationSetSpeed(uint16_t speed)
{
    navData.speed = speed;

    navigationTouch();
}

//
// ==========================================================
// GETTERS
// ==========================================================
//

bool navigationActive()
{
    return navData.active;
}

bool navigationHasGPS()
{
    return navData.hasGPS;
}

TurnType navigationTurn()
{
    return navData.turn;
}

String navigationRoad()
{
    return navData.road;
}

uint32_t navigationDistance()
{
    return navData.distance;
}

uint16_t navigationETA()
{
    return navData.eta;
}

uint16_t navigationSpeed()
{
    return navData.speed;
}
