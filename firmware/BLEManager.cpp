#include "BLEManager.h"
#include "NavigationManager.h"
#include "config.h"

BLEManager BLE;

bool BLEManager::m_connected = false;
bool BLEManager::m_packetAvailable = false;
NavigationPacket BLEManager::m_packet;

BLEManager::BLEManager()
{
    server = nullptr;
    service = nullptr;
    rxCharacteristic = nullptr;
    txCharacteristic = nullptr;
}

bool BLEManager::begin()
{
    NimBLEDevice::init(BLE_DEVICE_NAME);

    server = NimBLEDevice::createServer();

    server->setCallbacks(new ServerCallbacks());

    service = server->createService(BLE_SERVICE_UUID);

    rxCharacteristic = service->createCharacteristic(
        BLE_CHARACTERISTIC_RX,
        NIMBLE_PROPERTY::WRITE |
        NIMBLE_PROPERTY::WRITE_NR
    );

    txCharacteristic = service->createCharacteristic(
        BLE_CHARACTERISTIC_TX,
        NIMBLE_PROPERTY::NOTIFY
    );

    rxCharacteristic->setCallbacks(
        new RXCallbacks()
    );

    service->start();

    NimBLEAdvertising* advertising =
        NimBLEDevice::getAdvertising();

    advertising->addServiceUUID(
        BLE_SERVICE_UUID
    );

    advertising->setScanResponse(true);

    advertising->start();

    Serial.println("BLE Ready");
void BLEManager::update()
{

}

bool BLEManager::isConnected() const
{
    return m_connected;
}

bool BLEManager::hasPacket() const
{
    return m_packetAvailable;
}

NavigationPacket BLEManager::getPacket()
{
    m_packetAvailable = false;

    return m_packet;
}
    return true;
}
void BLEManager::sendBattery(uint8_t percent)
{
    if(!m_connected)
        return;

    uint8_t data[2];

    data[0] = 0x02;
    data[1] = percent;

    txCharacteristic->setValue(
        data,
        sizeof(data)
    );

    txCharacteristic->notify();
}
