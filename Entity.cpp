#include "Entity.h"

namespace A6 {

bool entitiesEqual(const Entity &a, const Entity &b)
{
    return (a.m_centre == b.m_centre &&
            a.m_velocity == b.m_velocity &&
            a.m_angle == b.m_angle &&
            a.m_angularRate == b.m_angularRate &&
            a.m_age == b.m_age);
}
 
};