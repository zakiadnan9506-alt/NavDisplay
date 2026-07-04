/**************************************************************************
 *
 *  NavDisplay Firmware v1.0
 *
 *  File        : utils.cpp
 *  Description : Utility Functions
 *
 **************************************************************************/

#include "utils.h"

//
// ==========================================================
// DISTANCE FORMAT
// ==========================================================
//

String formatDistance(uint32_t meter)
{
    if (meter < 1000)
    {
        return String(meter) + " m";
    }

    float km = meter / 1000.0f;

    if (km < 10.0f)
    {
        return String(km, 1) + " km";
    }

    return String((uint32_t)km) + " km";
}

//
// ==========================================================
// ETA FORMAT
// ==========================================================
//

String formatETA(uint16_t minute)
{
    if (minute < 60)
    {
        return String(minute) + " min";
    }

    uint16_t hour = minute / 60;
    uint16_t min = minute % 60;

    if (min == 0)
    {
        return String(hour) + " h";
    }

    return String(hour) + " h " + String(min) + " min";
}

//
// ==========================================================
// SPEED FORMAT
// ==========================================================
//

String formatSpeed(uint16_t kmh)
{
    return String(kmh) + " km/h";
}

//
// ==========================================================
// CLAMP PERCENT
// ==========================================================
//

uint8_t clampPercent(int value)
{
    if (value < 0)
    {
        return 0;
    }

    if (value > 100)
    {
        return 100;
    }

    return (uint8_t)value;
}

//
// ==========================================================
// TRUNCATE TEXT
// ==========================================================
//

String truncateText(const String &text, size_t maxLength)
{
    if (text.length() <= maxLength)
    {
        return text;
    }

    if (maxLength <= 3)
    {
        return text.substring(0, maxLength);
    }

    return text.substring(0, maxLength - 3) + "...";
}

//
// ==========================================================
// TIME FORMAT
// ==========================================================
//

String formatTime(uint32_t seconds)
{
    uint32_t hour = seconds / 3600;
    uint32_t minute = (seconds % 3600) / 60;
    uint32_t sec = seconds % 60;

    String result;

    if (hour > 0)
    {
        result += String(hour);
        result += "h ";
    }

    if (minute > 0 || hour > 0)
    {
        result += String(minute);
        result += "m ";
    }

    result += String(sec);
    result += "s";

    return result;
}
