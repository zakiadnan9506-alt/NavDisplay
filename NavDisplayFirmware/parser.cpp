/**************************************************************************
 *
 * NavDisplay Firmware v1.0
 *
 * File : parser.cpp
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
    parserDebug("Parser initialized");
}

//
// ==========================================================
// TURN PARSER
// ==========================================================
//

TurnType parserTurnFromString(const String &value)
{
    String turn = value;
    turn.trim();
    turn.toUpperCase();

    if (turn == "STRAIGHT")
        return TurnType::STRAIGHT;

    if (turn == "SLIGHT_LEFT")
        return TurnType::SLIGHT_LEFT;

    if (turn == "LEFT")
        return TurnType::LEFT;

    if (turn == "SHARP_LEFT")
        return TurnType::SHARP_LEFT;

    if (turn == "SLIGHT_RIGHT")
        return TurnType::SLIGHT_RIGHT;

    if (turn == "RIGHT")
        return TurnType::RIGHT;

    if (turn == "SHARP_RIGHT")
        return TurnType::SHARP_RIGHT;

    if (turn == "UTURN_LEFT")
        return TurnType::UTURN_LEFT;

    if (turn == "UTURN_RIGHT")
        return TurnType::UTURN_RIGHT;

    if (turn == "ROUNDABOUT")
        return TurnType::ROUNDABOUT;

    if (turn == "ARRIVE")
        return TurnType::ARRIVE;

    if (turn == "NONE")
        return TurnType::NONE;

    return TurnType::UNKNOWN;
}

//
// ==========================================================
// DEBUG
// ==========================================================
//

void parserDebug(const String &msg)
{
#ifdef DEBUG_SERIAL

    Serial.print("[Parser] ");
    Serial.println(msg);

#else

    (void)msg;

#endif
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

    bool parsed = false;

    int start = 0;

    while (start < packet.length())
    {
        int end = packet.indexOf(';', start);

        if (end == -1)
        {
            end = packet.length();
        }

        String token = packet.substring(start, end);

        token.trim();

        if (!token.isEmpty())
        {
            int eq = token.indexOf('=');

            if (eq > 0)
            {
                String key = token.substring(0, eq);
                String value = token.substring(eq + 1);

                key.trim();
                value.trim();

                key.toUpperCase();
                //----------------------------------------------------------
                // ACTIVE
                //----------------------------------------------------------

                if (key == "ACTIVE")
                {
                    navigationSetActive(
                        value == "1" ||
                        value.equalsIgnoreCase("TRUE"));

                    parsed = true;
                }

                //----------------------------------------------------------
                // GPS
                //----------------------------------------------------------

                else if (key == "GPS")
                {
                    navigationSetGPS(
                        value == "1" ||
                        value.equalsIgnoreCase("TRUE"));

                    parsed = true;
                }

                //----------------------------------------------------------
                // ROAD
                //----------------------------------------------------------

                else if (key == "ROAD")
                {
                    navigationSetRoad(value);

                    parsed = true;
                }

                //----------------------------------------------------------
                // DISTANCE
                //----------------------------------------------------------

                else if (key == "DIST")
                {
                    navigationSetDistance(
                        (uint32_t)value.toInt());

                    parsed = true;
                }

                //----------------------------------------------------------
                // ETA
                //----------------------------------------------------------

                else if (key == "ETA")
                {
                    navigationSetETA(
                        (uint16_t)value.toInt());

                    parsed = true;
                }

                //----------------------------------------------------------
                // SPEED
                //----------------------------------------------------------

                else if (key == "SPD")
                {
                    navigationSetSpeed(
                        (uint16_t)value.toInt());

                    parsed = true;
                }

                //----------------------------------------------------------
                // TURN
                //----------------------------------------------------------

                else if (key == "TURN")
                {
                    navigationSetTurn(
                        parserTurnFromString(value));

                    parsed = true;
                }

#ifdef DEBUG_SERIAL
                else
                {
                    parserDebug(
                        "Unknown key : " + key);
                }
#endif

            }
        }

        start = end + 1;
    }

    return parsed;
}
