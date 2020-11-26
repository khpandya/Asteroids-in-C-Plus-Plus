#if !defined(VECS_H)
#define VECS_H

#include <iostream>
using std::ostream;

namespace A6 {

/**
 * A two-dimensional Cartesian vector, which could represent a point defined 
 * with respect to the origin or a velocity vector.
 */
struct CartVec {
    double x, y;
};

/**
 * A two-dimensional vector in polar coordinates.  Why not just use CartVec?
 * Using 'theta' and 'rho' instead of 'x' and 'y' will enhance readability.
 */
struct PolarVec {
    // The angle
    double theta;
    
    // Distance from the origin.
    double rho;
};

// Overload equality and inequality operators for both types.
bool operator== (const CartVec &v1, const CartVec &v2);
bool operator!= (const CartVec &v1, const CartVec &v2);
bool operator== (const PolarVec &v1, const PolarVec &v2);
bool operator!= (const PolarVec &v1, const PolarVec &v2);

// Overload stream output operator for both types.
ostream& operator<<(ostream& os, const CartVec& v);
ostream& operator<<(ostream& os, const PolarVec& v);

};

#endif // !defined(VECS_H)