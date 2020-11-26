#include "collisions.h"
using std::make_pair;

namespace A6 {

vector<pair<Body, Body>> getCollidedPairs(const vector<Body>& aBodies, const vector<Body>& bBodies)
{
    vector<pair<Body, Body>> collidingBodies;
    int aBodiesSize=aBodies.size();
    int bBodiesSize=bBodies.size();
    for(int i=0;i<aBodiesSize;i++)
    {
        for(int j=0;j<bBodiesSize;j++)
        {
            bool isColliding=checkIntersect(aBodies[i],bBodies[j]);
            if(isColliding)
            {
                collidingBodies.push_back(make_pair(aBodies[i],bBodies[j]));
            }
        }
    }
    return collidingBodies;
}

void bulletsOnAsteroids(vector<Body>& bullets, vector<Body>& asteroids)
{
    //get colliding bullets and asteroids
    vector<pair<Body, Body>> collidingBodies=getCollidedPairs(bullets,asteroids);
    int numOfCollisions=collidingBodies.size();
    //go through all colliding bodies
    for(int i=0;i<numOfCollisions;i++)
    {   //need to update size of both given vectors since their sizes are changing dynamically
        int numOfBullets=bullets.size();
        int numOFAsteroids=asteroids.size();
        //remove colliding bullet from bullets
        for(int j=0;j<numOfBullets;j++)
        {
            if(collidingBodies[i].first==bullets[j])
            {
                bullets.erase(bullets.begin()+j);
            }
        }
        //obtain the fragments from original asteroid, then search for the original asteroid in asteroids and remove it, then add the fragments to asteroids
        vector<Body> fragments=collidingBodies[i].second.split();
        for(int k=0;k<numOFAsteroids;k++)
        {
            if(collidingBodies[i].second==asteroids[k])
            {
                asteroids.erase(asteroids.begin()+k);
            }
        }
        asteroids.push_back(fragments[0]);
        asteroids.push_back(fragments[1]);
    }
}

};
