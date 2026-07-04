/**************************************************************************
 *
 *  NavDisplay Firmware v1.0
 *
 *  File        : parser.cpp
 *  Description : BLE Navigation Packet Parser
 *
 **************************************************************************/

#include "parser.h"

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

void parserBegin()
{
    systemStatus.parserReady = true;
}

//
// ==========================================================
// DEBUG
// ==========================================================
//

void parserDebug(const String &msg)
{
#if ENABLE_SERIAL_DEBUG
    Serial.print("[PARSER] ");
    Serial.println(msg);
#endif
}

//
// ==========================================================
// TURN CONVERTER
// ==========================================================
//

TurnType parserTurnFromString(const String &value)
{
    if (value == "STRAIGHT")      return TurnType::STRAIGHT;

    if (value == "LEFT")          return TurnType::LEFT;
    if (value == "RIGHT")         return TurnType::RIGHT;

    if (value == "SLIGHT_LEFT")   return TurnType::SLIGHT_LEFT;
    if (value == "SLIGHT_RIGHT")  return TurnType::SLIGHT_RIGHT;

    if (value == "SHARP_LEFT")    return TurnType::SHARP_LEFT;
    if (value == "SHARP_RIGHT")   return TurnType::SHARP_RIGHT;

    if (value == "UTURN_LEFT")    return TurnType::UTURN_LEFT;
    if (value == "UTURN_RIGHT")   return TurnType::UTURN_RIGHT;

    if (value == "ROUNDABOUT")    return TurnType::ROUNDABOUT;

    if (value == "ARRIVE")        return TurnType::ARRIVE;

    return TurnType::UNKNOWN;
}

//
// ==========================================================
// PARSER
// ==========================================================
//

bool parserParse(const String &packet)
{
    if (packet.isEmpty())
    {
        return false;
    }

    int start = 0;

    while (start < packet.length())
    {
        int end = packet.indexOf(';', start);

        if (end < 0)
        {
            end = packet.length();
        }

        String item = packet.substring(start, end);

        int sep = item.indexOf('=');

        if (sep > 0)
        {
            String key = item.substring(0, sep);
            String value = item.substring(sep + 1);

            key.trim();
            value.trim();

            //--------------------------------------------------
            // ACTIVE
            //--------------------------------------------------

            if (key == "ACTIVE")
            {
                navigationSetActive(value.toInt() != 0);
            }

            //--------------------------------------------------
            // GPS
            //--------------------------------------------------

            else if (key == "GPS")
            {
                navigationSetGPS(value.toInt() != 0);
            }

            //--------------------------------------------------
            // ROAD
            //--------------------------------------------------

            else if (key == "ROAD")
            {
                navigationSetRoad(value);
            }

            //--------------------------------------------------
            // DISTANCE
            //--------------------------------------------------

            else if (key == "DIST")
            {
                navigationSetDistance(value.toInt());
            }

            //--------------------------------------------------
            // ETA
            //--------------------------------------------------

            else if (key == "ETA")
            {
                navigationSetETA(value.toInt());
            }

            //--------------------------------------------------
            // SPEED
            //--------------------------------------------------

            else if (key == "SPD")
            {
                navigationSetSpeed(value.toInt());
            }

            //--------------------------------------------------
            // TURN
            //--------------------------------------------------

            else if (key == "TURN")
            {
                navigationSetTurn(
                    parserTurnFromString(value)
                );
            }
        }

        start = end + 1;
    }

    return true;
}
