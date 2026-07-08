/**************************************************************************
 *
 * NavDisplay Framework v1.0
 *
 * parser.cpp
 *
 **************************************************************************/

#include "parser.h"

//
// ==========================================================
// TURN TABLE
// ==========================================================
//

struct TurnMap
{
    const char* name;
    TurnType type;
};

static const TurnMap turnTable[] =
{
    {"NONE",TurnType::NONE},

    {"STRAIGHT",TurnType::STRAIGHT},
    {"CONTINUE",TurnType::CONTINUE},

    {"SLIGHT_LEFT",TurnType::SLIGHT_LEFT},
    {"LEFT",TurnType::LEFT},
    {"SHARP_LEFT",TurnType::SHARP_LEFT},

    {"SLIGHT_RIGHT",TurnType::SLIGHT_RIGHT},
    {"RIGHT",TurnType::RIGHT},
    {"SHARP_RIGHT",TurnType::SHARP_RIGHT},

    {"KEEP_LEFT",TurnType::KEEP_LEFT},
    {"KEEP_RIGHT",TurnType::KEEP_RIGHT},

    {"MERGE_LEFT",TurnType::MERGE_LEFT},
    {"MERGE_RIGHT",TurnType::MERGE_RIGHT},

    {"FORK_LEFT",TurnType::FORK_LEFT},
    {"FORK_RIGHT",TurnType::FORK_RIGHT},

    {"RAMP_LEFT",TurnType::RAMP_LEFT},
    {"RAMP_RIGHT",TurnType::RAMP_RIGHT},

    {"EXIT_LEFT",TurnType::EXIT_LEFT},
    {"EXIT_RIGHT",TurnType::EXIT_RIGHT},

    {"UTURN_LEFT",TurnType::UTURN_LEFT},
    {"UTURN_RIGHT",TurnType::UTURN_RIGHT},

    {"ROUNDABOUT_1",TurnType::ROUNDABOUT_1},
    {"ROUNDABOUT_2",TurnType::ROUNDABOUT_2},
    {"ROUNDABOUT_3",TurnType::ROUNDABOUT_3},
    {"ROUNDABOUT_4",TurnType::ROUNDABOUT_4},
    {"ROUNDABOUT_5",TurnType::ROUNDABOUT_5},
    {"ROUNDABOUT_6",TurnType::ROUNDABOUT_6},
    {"ROUNDABOUT_7",TurnType::ROUNDABOUT_7},
    {"ROUNDABOUT_8",TurnType::ROUNDABOUT_8},

    {"ARRIVE_LEFT",TurnType::ARRIVE_LEFT},
    {"ARRIVE_RIGHT",TurnType::ARRIVE_RIGHT},
    {"DESTINATION",TurnType::DESTINATION},

    {"FERRY",TurnType::FERRY},
    {"TUNNEL",TurnType::TUNNEL},
    {"HIGHWAY",TurnType::HIGHWAY},
    {"TOLL_ROAD",TurnType::TOLL_ROAD},

    {"RECALCULATING",TurnType::RECALCULATING},
    {"GPS_LOST",TurnType::GPS_LOST}
};

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

TurnType parserTurnFromString(const String& value)
{
    String turn=value;

    turn.trim();

    turn.toUpperCase();

    for(const auto& item : turnTable)
    {
        if(turn.equals(item.name))
        {
            return item.type;
        }
    }

    return TurnType::UNKNOWN;
}

//
// ==========================================================
// TOKEN PARSER
// ==========================================================
//

bool parserParseToken(
    const String& key,
    const String& value)
{
    if(key=="ACTIVE")
    {
        navigationSetActive(
            value=="1"||
            value.equalsIgnoreCase("TRUE"));

        return true;
    }

    if(key=="GPS")
    {
        navigationSetGPS(
            value=="1"||
            value.equalsIgnoreCase("TRUE"));

        return true;
    }

    if(key=="ROAD")
    {
        navigationSetRoad(value);

        return true;
    }

    if(key=="DIST")
    {
        navigationSetDistance(value.toInt());

        return true;
    }

    if(key=="ETA")
    {
        navigationSetETA(value.toInt());

        return true;
    }

    if(key=="SPD")
    {
        navigationSetSpeed(value.toInt());

        return true;
    }

    if(key=="TURN")
    {
        navigationSetTurn(
            parserTurnFromString(value));

        return true;
    }

#if ENABLE_SERIAL_DEBUG

    parserDebug("Unknown key : "+key);

#endif

    return false;
}

//
// ==========================================================
// MAIN PARSER
// ==========================================================
//

bool parserParse(
    const String& packet)
{
    if(packet.isEmpty())
    {
        return false;
    }

    bool parsed=false;

    int start=0;

    while(start<packet.length())
    {
        int end=
            packet.indexOf(';',start);

        if(end<0)
        {
            end=packet.length();
        }

        String token=
            packet.substring(start,end);

        token.trim();

        if(!token.isEmpty())
        {
            int eq=
                token.indexOf('=');

            if(eq>0)
            {
                String key=
                    token.substring(0,eq);

                String value=
                    token.substring(eq+1);

                key.trim();

                value.trim();

                key.toUpperCase();

                parsed|=
                    parserParseToken(
                        key,
                        value);
            }
        }

        start=end+1;
    }

    return parsed;
}

//
// ==========================================================
// DEBUG
// ==========================================================
//

void parserDebug(
    const String& msg)
{
#if ENABLE_SERIAL_DEBUG

    Serial.print("[Parser] ");

    Serial.println(msg);

#else

    (void)msg;

#endif
}
