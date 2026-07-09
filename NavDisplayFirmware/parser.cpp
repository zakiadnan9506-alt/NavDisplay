#include "parser.h"

namespace NavDisplay
{

struct TurnMap
{
    const char* name;
    TurnType type;
};

static constexpr TurnMap turnTable[] =
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

void parserBegin()
{
    parserDebug(F("Parser initialized"));
}

TurnType parserTurnFromString(const String& value)
{
    String turn(value);

    turn.trim();
    turn.toUpperCase();

    for (const auto& item : turnTable)
    {
        if (turn.equals(item.name))
        {
            return item.type;
        }
    }

    return TurnType::UNKNOWN;
}

bool parserParseToken(
    const String& key,
    const String& value)
{
    if (key == F("ACTIVE"))
    {
        navigationSetActive(
            value == "1" ||
            value.equalsIgnoreCase("TRUE"));
        return true;
    }

    if (key == F("GPS"))
    {
        navigationSetGPS(
            value == "1" ||
            value.equalsIgnoreCase("TRUE"));
        return true;
    }

    if (key == F("ROAD"))
    {
        navigationSetRoad(value);
        return true;
    }

    if (key == F("DIST"))
    {
        navigationSetDistance(
            static_cast<uint32_t>(value.toInt()));
        return true;
    }

    if (key == F("ETA"))
    {
        navigationSetETA(
            static_cast<uint16_t>(value.toInt()));
        return true;
    }

    if (key == F("SPD"))
    {
        navigationSetSpeed(
            static_cast<uint16_t>(value.toInt()));
        return true;
    }

    if (key == F("TURN"))
    {
        navigationSetTurn(
            parserTurnFromString(value));
        return true;
    }

#if ENABLE_SERIAL_DEBUG
    parserDebug(String(F("Unknown key: ")) + key);
#endif

    return false;
}

bool parserParse(const String& packet)
{
    if (packet.isEmpty())
        return false;

    bool parsed = false;

    int start = 0;

    while (start < packet.length())
    {
        int end = packet.indexOf(';', start);

        if (end < 0)
            end = packet.length();

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
                key.toUpperCase();

                value.trim();

                parsed |= parserParseToken(key, value);
            }
        }

        start = end + 1;
    }

    return parsed;
}

void parserDebug(const String& msg)
{
#if ENABLE_SERIAL_DEBUG
    Serial.print(F("[Parser] "));
    Serial.println(msg);
#else
    (void)msg;
#endif
}

} // namespace NavDisplay
