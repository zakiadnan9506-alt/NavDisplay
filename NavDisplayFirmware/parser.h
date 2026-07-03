#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

#include "globals.h"

//
// =====================================================
// PARSER
// =====================================================
//

// Parse paket data BLE
void parseNavigationData(const String &data);

//
// =====================================================
// TURN TYPE
// =====================================================
//

TurnType parseTurnType(const String &turn);

String turnTypeToString(TurnType turn);

//
// =====================================================
// UTILITIES
// =====================================================
//

void clearNavigation();

#endif
