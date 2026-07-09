#include "layout.h"

namespace Layout
{

// ============================================================================
// Compile-time layout validation
// ============================================================================

static_assert(ScreenWidth > 0, "Invalid screen width.");
static_assert(ScreenHeight > 0, "Invalid screen height.");

static_assert(StatusBarHeight >= 0,
              "Status bar height must be positive.");

static_assert(StatusBarHeight < ScreenHeight,
              "Status bar exceeds screen height.");

static_assert(ContentWidth > 0,
              "Content width must be greater than zero.");

static_assert(ContentHeight > 0,
              "Content height must be greater than zero.");

static_assert(BatteryX >= 0,
              "Battery icon outside screen.");

static_assert(BLEIconX >= 0,
              "BLE icon outside screen.");

static_assert(GPSIconX >= 0,
              "GPS icon outside screen.");

static_assert(FooterY < ScreenHeight,
              "Footer outside screen.");

} // namespace Layout
