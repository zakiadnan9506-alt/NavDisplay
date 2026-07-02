#ifndef TYPES_H
#define TYPES_H

#include <Arduino.h>
#include "config.h"

/*=====================================================
  Connection State
=====================================================*/

enum class ConnectionState : uint8_t
{
    DISCONNECTED = 0,
    CONNECTING,
    CONNECTED
};

/*=====================================================
  Navigation Direction
=====================================================*/

enum class Direction : uint8_t
{
    NONE = 0,

    STRAIGHT,

    TURN_LEFT,

    TURN_RIGHT,

    SLIGHT_LEFT,

    SLIGHT_RIGHT,

    SHARP_LEFT,

    SHARP_RIGHT,

    UTURN,

    ROUNDABOUT,

    DESTINATION
};

/*=====================================================
  BLE Command
=====================================================*/

enum class Command : uint8_t
{
    NONE = 0,

    NAVIGATION,

    HEARTBEAT,

    BATTERY,

    DISPLAY,

    VERSION
};

/*=====================================================
  Navigation Packet
=====================================================*/

#pragma pack(push,1)

struct NavigationPacket
{
    uint8_t command;

    uint8_t direction;

    uint16_t distance;

    char road[ROAD_NAME_LENGTH];
};

#pragma pack(pop)

/*=====================================================
  Runtime Navigation State
=====================================================*/

struct NavigationState
{
    Direction direction;

    uint16_t distance;

    char road[ROAD_NAME_LENGTH];

    bool updated;

    NavigationState()
    {
        direction = Direction::NONE;
        distance = 0;

        memset(road,0,sizeof(road));

        updated = false;
    }
};

/*=====================================================
  Device State
=====================================================*/

struct DeviceState
{
    ConnectionState connection;

    bool displayReady;

    bool bleReady;

    DeviceState()
    {
        connection = ConnectionState::DISCONNECTED;

        displayReady = false;

        bleReady = false;
    }
};

#endif
