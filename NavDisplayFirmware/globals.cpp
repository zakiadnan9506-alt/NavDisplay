#include "globals.h"

//
// =====================================================
// GLOBAL VARIABLES
// =====================================================
//

NavigationData navData;

SystemStatus systemStatus;

BatteryStatus batteryStatus;

//
// =====================================================
// BLE OBJECTS
// =====================================================
//

NimBLEServer* bleServer = nullptr;

NimBLEService* bleService = nullptr;

NimBLECharacteristic* bleRxCharacteristic = nullptr;

NimBLECharacteristic* bleTxCharacteristic = nullptr;

//
// =====================================================
// TIMERS
// =====================================================
//

unsigned long lastDisplayRefresh = 0;
unsigned long lastBLEActivity = 0;
unsigned long lastBatteryRead = 0;

//
// =====================================================
// RESET NAVIGATION DATA
// =====================================================
//

void resetNavigationData()
{
    navData.active = false;

    navData.turn = TurnType::NONE;

    navData.roadName = "";

    navData.distance = 0;

    navData.speed = 0;

    navData.eta = 0;

    navData.gpsValid = false;

    navData.lastUpdate = millis();
}

//
// =====================================================
// RESET SYSTEM STATUS
// =====================================================
//

void resetSystemStatus()
{
    systemStatus.bleState = BLEState::DISCONNECTED;

    systemStatus.bleConnected = false;

    systemStatus.displayReady = false;

    systemStatus.newData = false;

    batteryStatus.voltage = 0.0f;

    batteryStatus.percent = 0;

    batteryStatus.charging = false;

    lastDisplayRefresh = 0;

    lastBLEActivity = 0;

    lastBatteryRead = 0;
}
