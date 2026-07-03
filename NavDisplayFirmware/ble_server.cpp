#include "ble_server.h"

//
// =====================================================
// FORWARD DECLARATION
// =====================================================
//

// Akan diimplementasikan pada parser.cpp
extern void parseNavigationData(const String &data);

//
// =====================================================
// CALLBACK OBJECTS
// =====================================================
//

static ServerCallbacks serverCallbacks;
static RXCallbacks rxCallbacks;

//
// =====================================================
// SERVER CALLBACKS
// =====================================================
//

void ServerCallbacks::onConnect(
    NimBLEServer *pServer,
    NimBLEConnInfo &connInfo)
{
    (void)pServer;
    (void)connInfo;

    systemStatus.bleConnected = true;
    systemStatus.bleState = BLEState::CONNECTED;

    lastBLEActivity = millis();

    DEBUG_PRINTLN("BLE Client Connected");
}

void ServerCallbacks::onDisconnect(
    NimBLEServer *pServer,
    NimBLEConnInfo &connInfo,
    int reason)
{
    (void)connInfo;
    (void)reason;

    systemStatus.bleConnected = false;
    systemStatus.bleState = BLEState::ADVERTISING;

    resetNavigationData();

    DEBUG_PRINTLN("BLE Client Disconnected");

    pServer->startAdvertising();
}

//
// =====================================================
// RX CALLBACK
// =====================================================
//

void RXCallbacks::onWrite(
    NimBLECharacteristic *pCharacteristic,
    NimBLEConnInfo &connInfo)
{
    (void)connInfo;

    std::string value = pCharacteristic->getValue();

    if (value.empty())
    {
        return;
    }

    lastBLEActivity = millis();

    String data(value.c_str());

    DEBUG_PRINT("RX : ");
    DEBUG_PRINTLN(data);

    parseNavigationData(data);
}

//
// =====================================================
// BLE INITIALIZATION
// =====================================================
//

bool bleBegin()
{
    DEBUG_PRINTLN("Initializing BLE...");

    NimBLEDevice::init(BLE_DEVICE_NAME);

    NimBLEDevice::setPower(ESP_PWR_LVL_P9);

    bleServer = NimBLEDevice::createServer();

    bleServer->setCallbacks(&serverCallbacks);

    bleService = bleServer->createService(BLE_SERVICE_UUID);

    //
    // RX Characteristic
    //

    bleRxCharacteristic = bleService->createCharacteristic(
        BLE_CHARACTERISTIC_RX_UUID,
        NIMBLE_PROPERTY::WRITE |
        NIMBLE_PROPERTY::WRITE_NR);

    bleRxCharacteristic->setCallbacks(&rxCallbacks);

    //
    // TX Characteristic
    //

    bleTxCharacteristic = bleService->createCharacteristic(
        BLE_CHARACTERISTIC_TX_UUID,
        NIMBLE_PROPERTY::READ |
        NIMBLE_PROPERTY::NOTIFY);

    bleTxCharacteristic->setValue("NavDisplay");

    bleService->start();

    bleStartAdvertising();

    DEBUG_PRINTLN("BLE Ready");

    return true;
}

//
// =====================================================
// START ADVERTISING
// =====================================================
//

void bleStartAdvertising()
{
    NimBLEAdvertising *advertising =
        NimBLEDevice::getAdvertising();

    advertising->addServiceUUID(BLE_SERVICE_UUID);

    advertising->setScanResponse(true);

    advertising->start();

    systemStatus.bleState = BLEState::ADVERTISING;

    DEBUG_PRINTLN("Advertising Started");
}

//
// =====================================================
// STOP ADVERTISING
// =====================================================
//

void bleStopAdvertising()
{
    NimBLEDevice::getAdvertising()->stop();

    DEBUG_PRINTLN("Advertising Stopped");
}

//
// =====================================================
// CONNECTION STATUS
// =====================================================
//

bool bleIsConnected()
{
    return systemStatus.bleConnected;
}

//
// =====================================================
// SEND DATA
// =====================================================
//

void bleSend(const String &message)
{
    if (!bleIsConnected())
    {
        return;
    }

    bleTxCharacteristic->setValue(message.c_str());

    bleTxCharacteristic->notify();
}

//
// =====================================================
// BLE LOOP
// =====================================================
//

void bleLoop()
{
    if (!bleIsConnected())
    {
        return;
    }

    if (millis() - lastBLEActivity > BLE_TIMEOUT_MS)
    {
        DEBUG_PRINTLN("BLE Timeout");

        resetNavigationData();
    }
}
