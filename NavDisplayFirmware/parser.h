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
// MAIN PARSER
// ==========================================================
//

bool parserParse(const String& packet);

//
// ==========================================================
// TOKEN PARSER
// ==========================================================
//

bool parserParseToken(
    const String& key,
    const String& value);

//
// ==========================================================
// TURN PARSER
// ==========================================================
//

TurnType parserTurnFromString(
    const String& value);

//
// ==========================================================
// DEBUG
// ==========================================================
//

void parserDebug(
    const String& msg);

#endif
