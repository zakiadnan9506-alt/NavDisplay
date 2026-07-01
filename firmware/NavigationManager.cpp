// Placeholder - will be filled in subsequent steps.
#include "NavigationManager.h"

#include <cstring>

NavigationManager navigation;

NavigationManager::NavigationManager()
{
    reset();
}

void NavigationManager::begin()
{
    reset();
}

void NavigationManager::reset()
{
    m_state.direction = Direction::NONE;

    m_state.distance = 0;

    memset(m_state.road,0,sizeof(m_state.road));

    m_state.connected = false;

    m_state.updated = true;
}

void NavigationManager::update()
{

    // Reserved
    // Future:
    // timeout
    // animation
    // ETA

}

void NavigationManager::setPacket(
    const NavigationPacket &packet
)
{

    m_state.direction =
        static_cast<Direction>(
            packet.direction
        );

    m_state.distance =
        packet.distance;

    memset(
        m_state.road,
        0,
        sizeof(m_state.road)
    );

    memcpy(

        m_state.road,

        packet.road,

        sizeof(m_state.road)

    );

    m_state.updated = true;

}

const NavigationState&
NavigationManager::state() const
{

    return m_state;

}

bool NavigationManager::hasUpdate() const
{

    return m_state.updated;

}

void NavigationManager::clearUpdate()
{

    m_state.updated = false;

}

void NavigationManager::setConnected(bool connected)
{

    if(m_state.connected != connected)
    {

        m_state.connected = connected;

        m_state.updated = true;

    }

}

bool NavigationManager::isConnected() const
{

    return m_state.connected;

}
