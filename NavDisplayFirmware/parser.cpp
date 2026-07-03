#include "parser.h"

//
// =====================================================
// PARSE BLE DATA
//
// Format:
//
// TURN=LEFT;
// ROAD=Jl. Ahmad Yani;
// DIST=350;
// SPEED=40;
// ETA=7;
// GPS=1;
// ACTIVE=1;
//
// =====================================================
//

void parseNavigationData(const String &data)
{
    String packet = data;

    packet.trim();

    int start = 0;

    while (start < packet.length())
    {
        int end = packet.indexOf(';', start);

        if (end < 0)
        {
            end = packet.length();
        }

        String token = packet.substring(start, end);

        token.trim();

        if (token.length())
        {
            int sep = token.indexOf('=');

            if (sep > 0)
            {
                String key = token.substring(0, sep);
                String value = token.substring(sep + 1);

                key.trim();
                value.trim();

                key.toUpperCase();

                if (key == "TURN")
                {
                    navData.turn = parseTurnType(value);
                }
                else if (key == "ROAD")
                {
                    navData.roadName = value;
                }
                else if (key == "DIST")
                {
                    navData.distance = value.toInt();
                }
                else if (key == "SPEED")
                {
                    navData.speed = value.toInt();
                }
                else if (key == "ETA")
                {
                    navData.eta = value.toInt();
                }
                else if (key == "GPS")
                {
                    navData.gpsValid = (value.toInt() != 0);
                }
                else if (key == "ACTIVE")
                {
                    navData.active = (value.toInt() != 0);
                }
            }
        }

        start = end + 1;
    }

    navData.lastUpdate = millis();

    systemStatus.newData = true;
}

//
// =====================================================
// TURN PARSER
// =====================================================
//

TurnType parseTurnType(const String &turn)
{
    String t = turn;

    t.trim();

    t.toUpperCase();

    if (t == "STRAIGHT")      return TurnType::STRAIGHT;
    if (t == "LEFT")          return TurnType::LEFT;
    if (t == "RIGHT")         return TurnType::RIGHT;
    if (t == "SLIGHT_LEFT")   return TurnType::SLIGHT_LEFT;
    if (t == "SLIGHT_RIGHT")  return TurnType::SLIGHT_RIGHT;
    if (t == "SHARP_LEFT")    return TurnType::SHARP_LEFT;
    if (t == "SHARP_RIGHT")   return TurnType::SHARP_RIGHT;
    if (t == "UTURN_LEFT")    return TurnType::UTURN_LEFT;
    if (t == "UTURN_RIGHT")   return TurnType::UTURN_RIGHT;
    if (t == "ROUNDABOUT")    return TurnType::ROUNDABOUT;
    if (t == "ARRIVE")        return TurnType::ARRIVE;
    if (t == "NONE")          return TurnType::NONE;

    return TurnType::UNKNOWN;
}

//
// =====================================================
// TURN TO STRING
// =====================================================
//

String turnTypeToString(TurnType turn)
{
    switch (turn)
    {
        case TurnType::NONE:          return "NONE";
        case TurnType::STRAIGHT:      return "STRAIGHT";
        case TurnType::LEFT:          return "LEFT";
        case TurnType::RIGHT:         return "RIGHT";
        case TurnType::SLIGHT_LEFT:   return "SLIGHT_LEFT";
        case TurnType::SLIGHT_RIGHT:  return "SLIGHT_RIGHT";
        case TurnType::SHARP_LEFT:    return "SHARP_LEFT";
        case TurnType::SHARP_RIGHT:   return "SHARP_RIGHT";
        case TurnType::UTURN_LEFT:    return "UTURN_LEFT";
        case TurnType::UTURN_RIGHT:   return "UTURN_RIGHT";
        case TurnType::ROUNDABOUT:    return "ROUNDABOUT";
        case TurnType::ARRIVE:        return "ARRIVE";
        default:                      return "UNKNOWN";
    }
}

//
// =====================================================
// CLEAR NAVIGATION
// =====================================================
//

void clearNavigation()
{
    resetNavigationData();
}
