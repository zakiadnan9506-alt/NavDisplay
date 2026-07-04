#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

#include "config.h"
#include "globals.h"
#include "navigation.h"

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

void parserBegin();

//
// ==========================================================
// PARSER
// ==========================================================
//

bool parserParse(const String &packet);

//
// ==========================================================
// HELPERS
// ==========================================================
//

TurnType parserTurnFromString(const String &value);

void parserDebug(const String &msg);

#endif
