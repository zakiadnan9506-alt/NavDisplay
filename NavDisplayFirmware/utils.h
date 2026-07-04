#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

//
// ==========================================================
// STRING
// ==========================================================
//

String formatDistance(uint32_t meter);

String formatETA(uint16_t minute);

String formatSpeed(uint16_t kmh);

//
// ==========================================================
// NUMBER
// ==========================================================
//

uint8_t clampPercent(int value);

//
// ==========================================================
// TEXT
// ==========================================================
//

String truncateText(const String &text, size_t maxLength);

//
// ==========================================================
// TIME
// ==========================================================
//

String formatTime(uint32_t seconds);

#endif
