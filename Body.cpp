#define _USE_MATH_DEFINES
#include "Body.h"
#include <algorithm> // For std::max
#include <cmath>
#include <stdlib.h>
#include <iostream>
using std::max;
using std::cout;
using std::endl;

namespace A6 {

Body::Body(CartVec centre, CartVec velocity, double angle, double angularRate, int nSides, double maxRadius, Colour colour, bool smooth)
    : Entity(centre, velocity, angle, angularRate, 0)
    , m_colour(colour)
{
    if (nSides < 1)
        throw BodyConstructionException{};

    double radius;
    if (smooth)
        radius = maxRadius * (rand() / (1.0 * RAND_MAX));

    // An Body with nSides sides will have nSides + 1 vertices.
    PolarVec* vertexArray = new PolarVec[nSides + 1];
    for (int i=0; i < nSides + 1; i++) {
        if (i == nSides) {
            // The final vertex should have the same radius as the first.
            radius = vertexArray[0].rho;
        } else if (smooth) {
            // If smooth, then the radius differs only by a small amount
            // between CartVecs.
            radius += 0.1 * maxRadius * (0.5 - rand() / (1.0 * RAND_MAX));
            radius = max(radius, maxRadius);
        } else {
            radius = maxRadius * (rand() / (1.0 * RAND_MAX));
        }
        // On purpose, we choose to have a vertex at theta = 0 as well as
        // another vertex at theta = 2pi.
        double theta = i * 2 * M_PI / nSides;
        vertexArray[i] = PolarVec{theta, radius};
    }

    m_pTriFan = new TriFan{vertexArray, nSides + 1};
    delete[] vertexArray;
}

Body::Body(CartVec centre, CartVec velocity, double angle, double angularRate, TriFan* pTriFan, Colour colour)
    : Entity{centre, velocity, angle, angularRate, 0}
    , m_pTriFan{pTriFan}
    , m_colour{colour}
{
}

Body::Body(const Body& other)
    : Entity{other.m_centre, other.m_velocity, other.m_angle, other.m_angularRate, other.m_age}
    , m_pTriFan{new TriFan{*other.m_pTriFan}}
    , m_colour{other.m_colour}
{
}

Body& Body::operator=(const Body& other)
{
    if (this != &other) {
        m_centre = other.m_centre;
        m_velocity = other.m_velocity;
        m_angle = other.m_angle;
        m_angularRate = other.m_angularRate;
        m_colour = other.m_colour;
        m_age = other.m_age;
        delete m_pTriFan;
        m_pTriFan = new TriFan{*other.m_pTriFan};
    }
    return *this;
}

Body::~Body()
{
    delete m_pTriFan;
}

bool Body::canSplit()
{
    return (m_pTriFan->numberOfVertices() > 2);
}

vector<Body> Body::split()
{
    if (m_pTriFan->numberOfVertices() <= 2) {
        throw BodySplitException{};
    }

    TriFan *pieceOne = nullptr;
    TriFan *pieceTwo = nullptr;
    m_pTriFan->split1(pieceOne, pieceTwo);

    // Create dimmer colors for the pieces.
    int m = 20; // Max reduction per color channel.
    Colour dimColour1 = m_colour.getRandomlyDimmedColour(20);
    Colour dimColour2 = m_colour.getRandomlyDimmedColour(20);

    Body left{m_centre, m_velocity, m_angle, m_angularRate, pieceOne, dimColour1};
    CartVec avgPos = left.averageVertexPosition();
    double vFactor = 1e-4; // Velocity conversion factor
    left.m_velocity.x += vFactor * (avgPos.x - left.m_centre.x);
    left.m_velocity.y += vFactor * (avgPos.y - left.m_centre.y);

    Body right{m_centre, m_velocity, m_angle, m_angularRate, pieceTwo, dimColour2};
    avgPos = right.averageVertexPosition();
    right.m_velocity.x += vFactor * (avgPos.x - left.m_centre.x);
    right.m_velocity.y += vFactor * (avgPos.y - left.m_centre.y);

    vector<Body> fragments{ left, right };
    return fragments;
}

CartVec Body::averageVertexPosition()
{
    vector<CartVec> vec = vertexPositions();

    CartVec avg{0, 0};
    for (CartVec& v : vec) {
        avg.x += v.x;
        avg.y += v.y;
    }
    int n = vec.size();
    if (n > 0) {
        avg.x /= n;
        avg.y /= n;
    }
    return avg;
}

vector<CartVec> Body::vertexPositions() const
{
    vector<CartVec> vPositions;
    int n = m_pTriFan->numberOfVertices();
    for (int i = 0; i < n; i++) {
        PolarVec p = m_pTriFan->getVertex(i);
        double x = m_centre.x + p.rho * cos(m_angle + p.theta);
        double y = m_centre.y + p.rho * sin(m_angle + p.theta);
        vPositions.push_back(CartVec{x, y});
    }
    return vPositions;
}

ostream& operator<<(ostream& os, Body b) {
    os << "Entity: ";
    os << "centre (" << b.m_centre.x << ", " << b.m_centre.y << ")";
    os << ", velocity (" << b.m_velocity.x << ", " << b.m_velocity.y << ")";
    os << ", angle " << b.m_angle;
    os << ", angularRate " << b.m_angularRate;
    os << ", age " << b.m_age << endl;

    os << "TriFan: " << *b.m_pTriFan << endl;

    os << "Colour: " << b.m_colour << endl;
    return os;
}

bool operator==(const Body &a, const Body &b)
{
    return (entitiesEqual(a, b) &&
            *a.m_pTriFan == *b.m_pTriFan &&
            a.m_colour == b.m_colour);
}

bool operator!=(const Body &a, const Body &b)
{
    return !(a == b);
}

// The following was adapted from W. Randolph Franklin's "Point Inclusion in
// Polygon Test": https://wrf.ecse.rpi.edu/Research/Short_Notes/pnpoly.html
bool pnpoly(const vector<CartVec>& verts, double testx, float testy)
{
    int nvert = verts.size();
    int i, j, c = 0;
    for (i = 0, j = nvert - 1; i < nvert; j = i++) {
        if (((verts[i].y > testy) != (verts[j].y > testy)) && (testx < (verts[j].x - verts[i].x) * (testy - verts[i].y) / (verts[j].y - verts[i].y) + verts[i].x))
            c = !c;
    }
    return c == 1; // 1 means strictly interior
}

bool checkIntersect(const Body& a, const Body& b)
{
    vector<CartVec> aVerts = a.vertexPositions();
    vector<CartVec> bVerts = b.vertexPositions();

    // The pnpoly function expects polygons, but our notion of a TriFan
    // is not the same as a polygon.  To make it a polygon we incorporate the
    // centre (this is required for TriFans where the centre is actually on
    // interior, so in some cases we could avoid this).
    aVerts.push_back(a.centre());
    bVerts.push_back(b.centre());

    for (const CartVec& av : aVerts) {
        if (pnpoly(bVerts, av.x, av.y))
            return true;
    }

    // We have to repeat this with the roles of a and be reversed, since pnpoly
    // is doing point-polygon intersection, not polygon-polygon intersection.
    for (const CartVec& bv : bVerts) {
        if (pnpoly(aVerts, bv.x, bv.y))
            return true;
    }

    return false;
}

};
