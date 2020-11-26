#include "Colour.h"

namespace A6 {

ostream& operator<<(ostream& os, Colour c) {
    os << "(" << +c.red << ", " << +c.green << ", " << +c.blue << ")" << endl;
    return os;
}

bool operator==(const Colour &a, const Colour &b)
{
    return (a.red == b.red && a.green == b.green && a.blue == b.blue && a.alpha == b.alpha);
}
 
bool operator!=(const Colour &a, const Colour &b)
{
    return !(a == b);
}

Colour operator+(const Colour& left, const Colour& right)
{
    return Colour{ static_cast<uint8_t>(min(left.red + right.red, 255)),
                   static_cast<uint8_t>(min(left.green + right.green, 255)),
                   static_cast<uint8_t>(min(left.blue + right.blue, 255)),
                   static_cast<uint8_t>(min(left.alpha + right.alpha, 255)) };
}

Colour operator-(const Colour& left, const Colour& right)
{
    return Colour{ static_cast<uint8_t>(min(left.red - right.red, 255)),
                   static_cast<uint8_t>(min(left.green - right.green, 255)),
                   static_cast<uint8_t>(min(left.blue - right.blue, 255)),
                   static_cast<uint8_t>(min(left.alpha - right.alpha, 255)) };
}

const Colour Colour::Black{0, 0, 0, 255};
const Colour Colour::White{255, 255, 255, 255};
const Colour Colour::Red{255, 0, 0, 255};
const Colour Colour::Green{0, 255, 0, 255};
const Colour Colour::Blue{0, 0, 255, 255};

};