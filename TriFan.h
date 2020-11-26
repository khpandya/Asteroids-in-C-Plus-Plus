#if !defined(TRIFAN_H)
#define TRIFAN_H

#include "Vecs.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

namespace A6 {

class TriFanConstructionException { };
class TriFanSplitException { };

/**
 * A TriFan represents a set of triangles which all share one common point.
 * The set of the other vertices (not the common point) are stored within an
 * array of PolarVec objects.  These give the positions of these vertices in
 * polar coordinates.  A TriFan can be split in two, as described in detail in
 * the assignment.
 */
class TriFan {

public:
    /**
     * Construct a TriFan from the given array of PolarVec's which are the
     * vertices of the TriFan, in polar coordinates.
     * 
     * @param vertexArray   An array of 2 or more vertices.  A
     *                      TriFanConstructionException will be thrown 
     *                      if less than 2 vertices are supplied.
     * 
     * The ordering of vertices in the array is significant.  The first pair
     * of vertices (vertexArray[0] and vertexArray[1]) will represent the first 
     * triangle.  The next vertex (vertexArray[2]) will pair with vertexArray[1]
     * to represent the next triangle.  Of course, 3 points are required to
     * represent a triangle.  The third point is the implicit origin at (0, 0)
     * and all given vertices are defined with respect to this origin.
     */ 
    TriFan(const PolarVec vertexArray[], int nVertices);

    /**
     * Copy constructor.
     */
    TriFan(const TriFan& other);

    /**
     * Copy assignment operator.
     */
    TriFan& operator=(const TriFan& other);

    /**
     * Destructor.  Deallocates array.
     */
    ~TriFan();

    /**
     * Split this TriFan into two pieces, meaning that the current TriFan's
     * array of vertices will separated into two arrays, with each of these
     * two arrays being used to construct a TriFan.  Those two TriFan's are
     * returned to the caller via the two 'piece' parameters.  Let n be the
     * number of vertices (the result of calling numberOfVertices).  The
     * split will occur at vertex n / 2 (integer division).   The vertex
     * where the split occurs will be included in both TriFans.
     * 
     * @param   pieceOne    Pointer to one of the two TriFans created
     * @param   pieceTwo    Pointer to the other
     * 
     * Notes:
     * - If the number of vertices is less than two then this function
     *   should throw TriFanSplitException.
     * - The caller is responsible for destroying the two pieces whenever
     *   necessary.
     */
    void split1(TriFan*& pieceOne, TriFan*& pieceTwo) const;

    /**
     * This function serves the same purpose as split1 and everything in the
     * comments for split1 applies---with the exception that the TriFan
     * to be split is passed in via the first argument.
     */
    friend void split2(const TriFan *input, TriFan*& pieceOne, TriFan*& pieceTwo);

    int numberOfVertices() const { return m_nVertices; }

    PolarVec getVertex(int i) const { return m_pVertices[i]; }

    friend ostream& operator<<(ostream& os, TriFan t);

    // Overloading equality and inequality operators so that we can more
    // easily find TriFan's within containers such as vector.
    friend bool operator== (const TriFan &a, const TriFan &b);

    friend bool operator!= (const TriFan &a, const TriFan &b);

private:
    // Pointer to the array of vertices.
    PolarVec* m_pVertices;

    // The number of vertices.
    int m_nVertices;
};

};

#endif // !defined(TRIFAN_H)