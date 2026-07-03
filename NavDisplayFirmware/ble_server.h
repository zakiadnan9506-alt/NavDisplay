#ifndef BLE_SERVER_H
#define BLE_SERVER_H

#include <Arduino.h>
#include <NimBLEDevice.h>

#include "config.h"
#include "globals.h"

//
// =====================================================
// BLE CALLBACKS
// =====================================================
//

class ServerCallbacks : public NimBLEServerCallbacks
{
public:

    void onConnect(
        NimBLEServer* pServer,
        NimBLEConnInfo& connInfo
    ) override;

    void onDisconnect(
        NimBLEServer* pServer,
        NimBLEConnInfo& connInfo,
        int reason
    ) override;
};

class RXCallbacks : public NimBLECharacteristicCallbacks
{
public:

    void onWrite(
        NimBLECharacteristic* pCharacteristic,
        NimBLEConnInfo& connInfo
    ) override;
};

//
// =====================================================
// BLE FUNCTIONS
// =====================================================
//

bool bleBegin();

void bleStartAdvertising();

void bleStopAdvertising();

bool bleIsConnected();

void bleSend(const String& message);

void bleLoop();

#endif
