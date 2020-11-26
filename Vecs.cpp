#include "Vecs.h"

namespace A6 {

//
// Overloading equality and inequality operators for both types.
//

bool operator== (const CartVec &v1, const CartVec &v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

bool operator!= (const CartVec &v1, const CartVec &v2)
{
    return !(v1 == v2);
}

bool operator== (const PolarVec &v1, const PolarVec &v2)
{
    return v1.theta == v2.theta && v1.rho == v2.rho;
}

bool operator!= (const PolarVec &v1, const PolarVec &v2)
{
    return !(v1 == v2);
}

ostream& operator<<(ostream& os, const CartVec& v)
{
    return os << "(" << v.x << ", " << v.y << ")";
}

ostream& operator<<(ostream& os, const PolarVec& v)
{
    return os << "(" << v.theta << ", " << v.rho << ")";
}

};