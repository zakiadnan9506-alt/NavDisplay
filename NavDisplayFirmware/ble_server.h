#ifndef BLE_SERVER_H
#define BLE_SERVER_H

#include <Arduino.h>

#include <NimBLEDevice.h>

#include "config.h"

//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

bool bleBegin();

//
// ==========================================================
// UPDATE
// ==========================================================
//

void bleUpdate();

//
// ==========================================================
// STATUS
// ==========================================================
//

bool bleIsConnected();

//
// ==========================================================
// SEND
// ==========================================================
//

void bleSend(const String &text);

//
// ==========================================================
// CALLBACKS
// ==========================================================
//

class ServerCallbacks : public NimBLEServerCallbacks
{
public:

    void onConnect(NimBLEServer *server) override;

    void onDisconnect(NimBLEServer *server) override;
};

class RXCallbacks : public NimBLECharacteristicCallbacks
{
public:

    void onWrite(NimBLECharacteristic *characteristic) override;
};

#endif
