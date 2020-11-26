#if !defined(COLLISIONS_H)
#define COLLISIONS_H

#include "Body.h"
#include <vector>
using std::vector;
using std::pair;

namespace A6 {

/**
 * Detect collisions between all of the bodies in aBodies and all of the bodies
 * in bBodies, returning a vector of pairs of bodies that are in collision with
 * each other.
 * 
 * STUDENTS:
 *  - Call the checkIntersect function declared in Body.h to check for
 *    collisions between Body objects.
 */
vector<pair<Body, Body>> getCollidedPairs(const vector<Body>& aBodies, const vector<Body>& bBodies);

/**
 * Check for collisions between the bodies in bullets and those in asteroids.
 * Each time there is a collision between a bullet (lets call it B) and an
 * asteroid (lets call it A), the following should happen:
 *  - B should be removed from bullets
 *  - A should be split into two bodies (use Body's split method).  The two
 *    pieces, A1 and A2, should be added to asteroids.  A should be removed
 *    from asteroids.
 * 
 * STUDENTS:
 *  - Call getCollidedPairs to determine the collisions that need to be handled.
 */
void bulletsOnAsteroids(vector<Body>& bullets, vector<Body>& asteroids);

};

#endif // !defined(COLLISIONS_H)