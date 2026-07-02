#ifndef BLE_MANAGER_H
#define BLE_MANAGER_H

#include <Arduino.h>

#include <NimBLEDevice.h>

#include "Types.h"

class BLEManager
{
public:

    BLEManager();

    bool begin();

    void update();

    bool isConnected() const;

    bool hasPacket() const;

    NavigationPacket getPacket();

    void sendBattery(uint8_t percent);

private:

    static bool m_connected;

    static bool m_packetAvailable;

    static NavigationPacket m_packet;

    NimBLEServer* server;

    NimBLEService* service;

    NimBLECharacteristic* rxCharacteristic;

    NimBLECharacteristic* txCharacteristic;

    class ServerCallbacks :
        public NimBLEServerCallbacks
    {
    public:

        void onConnect(
            NimBLEServer* server
        ) override;

        void onDisconnect(
            NimBLEServer* server
        ) override;

    };

    class RXCallbacks :
        public NimBLECharacteristicCallbacks
    {
    public:

        void onWrite(
            NimBLECharacteristic* characteristic
        ) override;

    };

};

extern BLEManager BLE;

#endif// Placeholder - will be filled in subsequent steps.
