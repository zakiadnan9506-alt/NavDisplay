/**************************************************************************
 *
 * NavDisplay Firmware v1.0
 *
 * File : battery.cpp
 * Description : Battery Manager
 *
 **************************************************************************/

#include "battery.h"

//
// ==========================================================
// INTERNAL
// ==========================================================
//

static float filteredVoltage = BATTERY_MIN_VOLT;

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

void batteryBegin()
{
    pinMode(BATTERY_ADC_PIN, INPUT);

    batteryData.voltage = BATTERY_MIN_VOLT;
    batteryData.percentage = 0;
    batteryData.charging = false;
    batteryData.lastUpdate = millis();

    systemStatus.batteryReady = true;
}

//
// ==========================================================
// UPDATE
// ==========================================================
//

void batteryUpdate()
{
    if (!systemStatus.batteryReady)
        return;

    float v = batteryReadVoltage();

    // Low Pass Filter
    filteredVoltage =
        filteredVoltage * 0.90f +
        v * 0.10f;

    batteryData.voltage = filteredVoltage;

    batteryData.percentage =
        batteryVoltageToPercent(filteredVoltage);

    batteryData.lastUpdate = millis();
}

//
// ==========================================================
// READ VOLTAGE
// ==========================================================
//

float batteryReadVoltage()
{
    uint16_t raw = analogRead(BATTERY_ADC_PIN);

    float voltage =
        ((float)raw / ADC_RESOLUTION) *
        ADC_REFERENCE *
        BATTERY_DIVIDER_RATIO;

    return voltage;
}

//
// ==========================================================
// VOLTAGE -> PERCENT
// ==========================================================
//

uint8_t batteryVoltageToPercent(float voltage)
{
    voltage = constrain(
        voltage,
        BATTERY_MIN_VOLT,
        BATTERY_MAX_VOLT
    );

    float percent =
        (voltage - BATTERY_MIN_VOLT) *
        100.0f /
        (BATTERY_MAX_VOLT - BATTERY_MIN_VOLT);

    return (uint8_t)percent;
}

//
// ==========================================================
// GETTERS
// ==========================================================
//

float batteryVoltage()
{
    return batteryData.voltage;
}

uint8_t batteryPercentage()
{
    return batteryData.percentage;
}

bool batteryCharging()
{
    return batteryData.charging;
}
