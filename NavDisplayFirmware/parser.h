#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

#include "globals.h"

//
// =====================================================
// PARSER
// =====================================================
//

// Parse seluruh paket data BLE
void parseNavigationData(const String &data);

//
// =====================================================
// UTILITIES
// =====================================================

// Mengubah string menjadi TurnType
TurnType parseTurnType(const String &turn);

// Mengubah TurnType menjadi string
String turnTypeToString(TurnType turn);

// Mengosongkan data navigasi
void clearNavigation();

#endif
