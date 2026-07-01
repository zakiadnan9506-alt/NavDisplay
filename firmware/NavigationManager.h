// Placeholder - will be #ifndef NAVIGATION_MANAGER_H
#define NAVIGATION_MANAGER_H

#include <Arduino.h>
#include "Types.h"

class NavigationManager
{
public:

    NavigationManager();

    void begin();

    void reset();

    void update();

    void setPacket(const NavigationPacket &packet);

    const NavigationState& state() const;

    bool hasUpdate() const;

    void clearUpdate();

    void setConnected(bool connected);

    bool isConnected() const;

private:

    NavigationState m_state;

};

extern NavigationManager navigation;

#endiffilled in subsequent steps.
