// Placeholder - will be filled in s#ifndef TYPES_H
#define TYPES_H

#include <Arduino.h>
#include "config.h"

/*
====================================================
Command
====================================================
*/

enum class Command : uint8_t
{
    NONE = 0,
    NAVIGATION = 1,
    PING = 2,
    SETTINGS = 3,
    BATTERY = 4
};

/*
====================================================
Direction
====================================================
*/

enum class Direction : uint8_t
{
    NONE = 0,

    STRAIGHT,

    LEFT,

    RIGHT,

    SLIGHT_LEFT,

    SLIGHT_RIGHT,

    SHARP_LEFT,

    SHARP_RIGHT,

    UTURN,

    ROUNDABOUT,

    ARRIVED
};

/*
====================================================
BLE Packet

Ukuran tetap
36 Byte
====================================================
*/

#pragma pack(push,1)

struct NavigationPacket
{
    uint8_t command;

    uint8_t direction;

    uint16_t distance;

    char road[MAX_ROAD_NAME];
};

#pragma pack(pop)

/*
====================================================
Navigation Runtime
====================================================
*/

struct NavigationState
{
    Direction direction;

    uint16_t distance;

    char road[MAX_ROAD_NAME];

    bool connected;

    bool updated;
};

#endifubsequent steps.
