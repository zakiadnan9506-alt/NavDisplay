/**************************************************************************
 *
 *  NavDisplay Firmware v1.0
 *
 *  File        : ble_server.cpp
 *  Description : BLE Server (Nordic UART Service)
 *
 **************************************************************************/

#include "ble_server.h"

#include "globals.h"
#include "parser.h"

//
// ==========================================================
// BLE OBJECTS
// ==========================================================
//

static NimBLEServer* bleServer = nullptr;

static NimBLEService* bleService = nullptr;

static NimBLECharacteristic* bleRX = nullptr;

static NimBLECharacteristic* bleTX = nullptr;

//
// ==========================================================
// SERVER CALLBACKS
// ==========================================================
//

void ServerCallbacks::onConnect(NimBLEServer* server)
{
    (void)server;

    systemStatus.bleConnected = true;

#if ENABLE_SERIAL_DEBUG
    Serial.println("[BLE] Connected");
#endif
}

void ServerCallbacks::onDisconnect(NimBLEServer* server)
{
    (void)server;

    systemStatus.bleConnected = false;

#if ENABLE_SERIAL_DEBUG
    Serial.println("[BLE] Disconnected");
#endif

    NimBLEDevice::startAdvertising();
}

//
// ==========================================================
// RX CALLBACK
// ==========================================================
//

void RXCallbacks::onWrite(NimBLECharacteristic* characteristic)
{
    std::string rx = characteristic->getValue();

    if (rx.empty())
    {
        return;
    }

    String packet(rx.c_str());

#if ENABLE_SERIAL_DEBUG
    Serial.print("[BLE RX] ");
    Serial.println(packet);
#endif

    parserParse(packet);
}

//
// ==========================================================
// BLE BEGIN
// ==========================================================
//

bool bleBegin()
{
    NimBLEDevice::init(BLE_DEVICE_NAME);

    bleServer = NimBLEDevice::createServer();

    bleServer->setCallbacks(new ServerCallbacks());

    bleService =
        bleServer->createService(
            BLE_SERVICE_UUID
        );

    bleRX =
        bleService->createCharacteristic(
            BLE_CHARACTERISTIC_RX_UUID,
            NIMBLE_PROPERTY::WRITE |
            NIMBLE_PROPERTY::WRITE_NR
        );

    bleTX =
        bleService->createCharacteristic(
            BLE_CHARACTERISTIC_TX_UUID,
            NIMBLE_PROPERTY::NOTIFY
        );

    bleRX->setCallbacks(new RXCallbacks());

    bleService->start();

    NimBLEAdvertising* advertising =
        NimBLEDevice::getAdvertising();

    advertising->addServiceUUID(
        BLE_SERVICE_UUID
    );

    advertising->setScanResponse(true);

    advertising->start();

#if ENABLE_SERIAL_DEBUG
    Serial.println("[BLE] Advertising...");
#endif

    return true;
}

//
// ==========================================================
// UPDATE
// ==========================================================
//

void bleUpdate()
{
    // Reserved
}

//
// ==========================================================
// STATUS
// ==========================================================
//

bool bleIsConnected()
{
    return systemStatus.bleConnected;
}

//
// ==========================================================
// SEND
// ==========================================================
//

void bleSend(const String& text)
{
    if (!bleIsConnected())
    {
        return;
    }

    bleTX->setValue(text.c_str());

    bleTX->notify();
}
