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

    NimBLEServer* server = nullptr;
    NimBLEService* service = nullptr;
    NimBLECharacteristic* rxCharacteristic = nullptr;
    NimBLECharacteristic* txCharacteristic = nullptr;

    class ServerCallbacks :
        public NimBLEServerCallbacks
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

        void onMTUChange(
            uint16_t mtu,
            NimBLEConnInfo& connInfo
        ) override;
    };

    class RXCallbacks :
        public NimBLECharacteristicCallbacks
    {
    public:

        void onWrite(
            NimBLECharacteristic* characteristic,
            NimBLEConnInfo& connInfo
        ) override;
    };
};

extern BLEManager BLE;

#endif
