#if !defined(BODY_H)
#define BODY_H

#include "Entity.h"
#include "TriFan.h"
#include "Vecs.h"
#include "Colour.h"
#include <vector>
using std::vector;

namespace A6 {

class BodyConstructionException { };
class BodySplitException { };

/**
 * An Body is an Entity that can be split into smaller pieces.  Its body
 * consists of a TriFan.
 */
class Body : public Entity {
public:
    /**
     * Constructor.  The first four parameters will set the four corresponding
     * members inherited from Entity.  The other parameters are as follows:
     * 
     * @param   nSides      The number of sides (or triangles)
     * @param   maxRadius   The maximum distance of a side from the centre
     * @param   smooth      Whether to maintain smoothness between adj. sides
     */
    Body(CartVec centre, CartVec velocity, double angle, double angularRate, int nSides, double maxRadius, Colour colour, bool smooth=true);

    /**
     * Construct an Body with the given Entity characteristcs, TriFan, and colour.
     */
    Body(CartVec centre, CartVec velocity, double angle, double angularRate, TriFan* pTriFan, Colour colour);

    /**
     * Destructor.
     */
    ~Body();

    /**
     * Copy constructor.
     */
    Body(const Body& other);

    /**
     * Copy assignment operator.
     */
    Body& operator=(const Body& other);

    /**
     * Return whether this Body can be split.
     */
    bool canSplit();

    /**
     * Split this Body into two pieces, returning the pieces in the return
     * vector.  If this Body cannot be split, it will just return itself
     * as the sole member of the vector.  This allows the calling code to just
     * deal with one case.
     */
    vector<Body> split();

    /**
     * Get the positions of all vertices in absolute coordinates, that is not
     * with respect to the centre, but with respect to the global origin.
     */
    vector<CartVec> vertexPositions() const;

    Colour colour() const { return m_colour; }

    void setColour(Colour c) { m_colour = c; }

    friend ostream& operator<<(ostream& os, Body e);

    // Overloading equality and inequality operators so that we can more
    // easily find Body's within containers such as vector.
    friend bool operator== (const Body &a, const Body &b);

    friend bool operator!= (const Body &a, const Body &b);

private:
    CartVec averageVertexPosition();

    // This Body's TriFan.
    TriFan* m_pTriFan;

    Colour m_colour;
};

/**
 * Check if the two given bodies intersect.
 */
bool checkIntersect(const Body& a, const Body& b);

};

#endif // !defined(BODY_H)