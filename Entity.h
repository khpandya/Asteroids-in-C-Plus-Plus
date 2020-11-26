#if !defined(ENTITY_H)
#define ENTITY_H

#include "Vecs.h"
#include <cmath>
#include <iostream>
using std::ostream;
using std::endl;

namespace A6 {

/**
 * An entity in the game, which has a position (of its centre), a velocity
 * vector, and a distance from the centre to each of the sides that can be
 * determined.
 */
class Entity {
public:
    CartVec centre() const { return m_centre; }

    double angle() const { return m_angle; }

    int age() const { return m_age; }

    void applyThrust(double amount)
    {
        m_velocity.x += amount * cos(m_angle);
        m_velocity.y += amount * sin(m_angle);
    }

    void adjustAngle(double amount)
    {
        m_angle += amount;
    }

    void update()
    {
        m_centre.x += m_velocity.x;
        m_centre.y += m_velocity.y;
        m_angle += m_angularRate;
        ++m_age;
    }

    void horizontalCollision(double overlap)
    {
        m_centre.x += overlap;
        m_velocity.x *= -1;
    }

    void verticalCollision(double overlap)
    {
        m_centre.y += overlap;
        m_velocity.y *= -1;
    }

protected:
    Entity(CartVec centre, CartVec velocity, double angle, double angularRate, int age)
        : m_centre(centre)
        , m_velocity(velocity)
        , m_angle(angle)
        , m_angularRate(angularRate)
        , m_age(age)
    {
    }

    // The centre CartVec of the entity.  Note that this is not necessarily,
    // the centre-of-mass or centre-of-gravity.
    CartVec m_centre;

    CartVec m_velocity;

    // The current angle (in radians) of this entity.
    double m_angle;

    // The rate of angular rotation.
    double m_angularRate;

    int m_age;

    // This is a non-abstract base class (so far, just for Body), and the issue 
    // of defining operators like equality can be confusing.  
    // Following the advice here:
    //  https://stackoverflow.com/questions/1691007/whats-the-right-way-to-overload-operator-for-a-class-hierarchy
    // we do not define this operators, but provide this function which can 
    // be called explicitly by derived classes instead.
    friend bool entitiesEqual(const Entity &a, const Entity &b);
};

};

#endif // !defined(ENTITY_H)