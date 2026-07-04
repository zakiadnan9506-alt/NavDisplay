/**************************************************************************
 *
 * NavDisplay Firmware v1.0
 *
 * File : ble_server.cpp
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

static NimBLEServer* server = nullptr;

static NimBLEService* service = nullptr;

static NimBLECharacteristic* rxCharacteristic = nullptr;

static NimBLECharacteristic* txCharacteristic = nullptr;

//
// ==========================================================
// CALLBACK OBJECTS
// ==========================================================
//

static ServerCallbacks serverCallbacks;

static RXCallbacks rxCallbacks;

//
// ==========================================================
// SERVER CALLBACKS
// ==========================================================
//

void ServerCallbacks::onConnect(NimBLEServer* pServer)
{
    (void)pServer;

    systemStatus.bleConnected = true;

#ifdef DEBUG_SERIAL
    Serial.println("[BLE] Connected");
#endif
}

void ServerCallbacks::onDisconnect(NimBLEServer* pServer)
{
    (void)pServer;

    systemStatus.bleConnected = false;

#ifdef DEBUG_SERIAL
    Serial.println("[BLE] Disconnected");
#endif
    if (server != nullptr)
    {
        server->startAdvertising();
    }
}
//
// ==========================================================
// RX CALLBACK
// ==========================================================
//

void RXCallbacks::onWrite(NimBLECharacteristic *characteristic)
{
    if (characteristic == nullptr)
    {
        return;
    }

    std::string rx = characteristic->getValue();

    if (rx.empty())
    {
        return;
    }

    String packet(rx.c_str());

#ifdef DEBUG_SERIAL
    Serial.print("[BLE RX] ");
    Serial.println(packet);
#endif

bool ok = parserParse(packet);

#ifdef DEBUG_SERIAL
if (!ok)
{
    Serial.println("[BLE] Invalid packet");
}
#endif
}
//
// ==========================================================
// SEND
// ==========================================================
//

void bleSend(const String &text)
{
    if (!systemStatus.bleConnected)
    {
        return;
    }

    if (txCharacteristic == nullptr)
    {
        return;
    }
   if (text.isEmpty())
{
    return;
}

    txCharacteristic->setValue(text.c_str());

    txCharacteristic->notify();

#ifdef DEBUG_SERIAL
    Serial.print("[BLE TX] ");
    Serial.println(text);
#endif
}
//
// ==========================================================
// INITIALIZATION
// ==========================================================
//

bool bleBegin()
{
    NimBLEDevice::init(BLE_DEVICE_NAME);
    systemStatus.bleConnected = false;

    server = NimBLEDevice::createServer();

    if (server == nullptr)
    {
        return false;
    }

    server->setCallbacks(&serverCallbacks);

    service = server->createService(BLE_SERVICE_UUID);

    if (service == nullptr)
    {
        return false;
    }

    //----------------------------------------------------------
    // RX Characteristic
    //----------------------------------------------------------

    rxCharacteristic = service->createCharacteristic(
        BLE_CHARACTERISTIC_RX_UUID,
        NIMBLE_PROPERTY::WRITE |
        NIMBLE_PROPERTY::WRITE_NR
    );

    if (rxCharacteristic == nullptr)
    {
        return false;
    }

    rxCharacteristic->setCallbacks(&rxCallbacks);

    //----------------------------------------------------------
    // TX Characteristic
    //----------------------------------------------------------

    txCharacteristic = service->createCharacteristic(
        BLE_CHARACTERISTIC_TX_UUID,
        NIMBLE_PROPERTY::READ |
        NIMBLE_PROPERTY::NOTIFY
    );

    if (txCharacteristic == nullptr)
    {
        return false;
    }

    service->start();

    NimBLEAdvertising* advertising = NimBLEDevice::getAdvertising();

advertising->addServiceUUID(BLE_SERVICE_UUID);
advertising->setName(BLE_DEVICE_NAME);
advertising->setScanResponse(true);
if (!advertising->start())
{
    return false;
}

#ifdef DEBUG_SERIAL
    Serial.println("[BLE] Advertising started");
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
    // Reserved for future use.
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
