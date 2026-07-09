#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

#include "config.h"
#include "globals.h"
#include "navigation.h"

namespace NavDisplay
{

// ============================================================================
// Initialization
// ============================================================================

void parserBegin();

// ============================================================================
// Main Parser
// ============================================================================

[[nodiscard]]
bool parserParse(const String& packet);

// ============================================================================
// Token Parser
// ============================================================================

[[nodiscard]]
bool parserParseToken(
    const String& key,
    const String& value);

// ============================================================================
// Turn Parser
// ============================================================================

[[nodiscard]]
TurnType parserTurnFromString(
    const String& value);

// ============================================================================
// Debug
// ============================================================================

void parserDebug(
    const String& msg);

} // namespace NavDisplay

#endif // PARSER_H
