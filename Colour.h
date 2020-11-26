#if !defined(COLOUR_H)
#define COLOUR_H

#include <cstdint> 
#include <stdlib.h> // For rand
#include <algorithm> // For std::min and std::max
#include <iostream>
using std::min;
using std::max;
using std::ostream;
using std::cout;
using std::endl;

namespace A6 {

/**
 * Representation of an RGBA colour (red, green, blue, alpha).
 */
struct Colour {
    static const Colour Black;
    static const Colour White;
    static const Colour Red;
    static const Colour Green;
    static const Colour Blue;

    static Colour getRandomColour(uint8_t alpha=255)
    {
        return Colour{ static_cast<uint8_t>(rand() % 256),
                       static_cast<uint8_t>(rand() % 256),
                       static_cast<uint8_t>(rand() % 256), alpha };
    }

    Colour getRandomlyDimmedColour(uint8_t maxDim)
    {
        return Colour{ static_cast<uint8_t>(max(red - rand() % maxDim, 0)),
                       static_cast<uint8_t>(max(green - rand() % maxDim, 0)),
                       static_cast<uint8_t>(max(blue - rand() % maxDim, 0)),
                       alpha };
    }

    Colour getWithRandomAlpha()
    {
        return Colour{ red, green, blue, static_cast<uint8_t>(rand() % 256) };
    }

    uint8_t red, green, blue, alpha;
};

ostream& operator<<(ostream& os, Colour c);

bool operator== (const Colour &a, const Colour &b);
bool operator!= (const Colour &a, const Colour &b);

Colour operator+(const Colour& left, const Colour& right);
Colour operator-(const Colour& left, const Colour& right);

};

#endif // !defined(COLOUR_H)