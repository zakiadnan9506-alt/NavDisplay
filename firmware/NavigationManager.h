#ifndef NAVIGATION_MANAGER_H
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

    Direction getDirection() const;

    uint16_t getDistance() const;

    const char* getRoadName() const;

    bool hasUpdate() const;

    void clearUpdate();

private:

    NavigationState m_state;

};

extern NavigationManager Navigation;

#endif
