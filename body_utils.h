/**
 * Utility functions to create Bodys and sets of Bodys for testing.
 */

#include "Body.h"
#include <string>
using namespace A6;
using std::string;

constexpr double PI_4 = 3.14159265358979323846 / 4.0;

Body createSquareBody(double x, double y, double sidelength)
{
    double h = sidelength / sqrt(2.);
    PolarVec p1{PI_4, h};
    PolarVec p2{3*PI_4, h};
    PolarVec p3{5*PI_4, h};
    PolarVec p4{7*PI_4, h};
    PolarVec vertexArray[]{ p1, p2, p3, p4, p1 };

    TriFan* tf = new TriFan{vertexArray, 5};
    return Body{CartVec{x,y}, CartVec{0,0}, 0, 0, tf, Colour::Black};
}

vector<Body> createSquaresOnGrid(int nHorz, double horzSpacing, int nVert, double vertSpacing, double sidelength)
{
    vector<Body> squares;
    for (int ny=0; ny < nVert; ++ny) {
        double y = (ny + 1) * vertSpacing;
        for (int nx=0; nx < nHorz; ++nx) {
            double x = (nx + 1) * horzSpacing;
            squares.push_back( createSquareBody(x, y, sidelength) );
        }
    }
    return squares;
}

//
// We define a set of different configurations for testing.
//

struct Config {
    vector<Body> aBodies;
    vector<Body> bBodies;
};

vector<Config> allConfigs()
{
    vector<Config> configs{

        //
        // Configs 0 - 7 have a single square in aBodies and a grid of 25x25 
        // squares in bBodies.  The single square grows and shifts in x.
        //

        // 0
        Config{
            vector<Body>{ createSquareBody(400, 300, 10) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 1
        , Config{
            vector<Body>{ createSquareBody(450, 300, 10) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 2
        , Config{
            vector<Body>{ createSquareBody(400, 300, 100) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 3
        , Config{
            vector<Body>{ createSquareBody(450, 300, 100) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 4
        , Config{
            vector<Body>{ createSquareBody(400, 300, 200) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 5
        , Config{
            vector<Body>{ createSquareBody(450, 300, 200) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 6
        , Config{
            vector<Body>{ createSquareBody(400, 300, 300) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 7
        , Config{
            vector<Body>{ createSquareBody(450, 300, 300) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }

        //
        // Configs 8 - 15 have a two squares in aBodies and a grid of 25x25 
        // squares in bBodies.  The left square is constant, but the right 
        // square grows and shifts in x.  The left square intersects with nothing.
        //

        // 8
        , Config{
            vector<Body>{ createSquareBody(50, 50, 10), createSquareBody(400, 300, 10) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 9
        , Config{
            vector<Body>{ createSquareBody(50, 50, 10), createSquareBody(450, 300, 10) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 10 
        , Config{
            vector<Body>{ createSquareBody(50, 50, 10), createSquareBody(400, 300, 100) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 11
        , Config{
            vector<Body>{ createSquareBody(50, 50, 10), createSquareBody(450, 300, 100) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 12
        , Config{
            vector<Body>{ createSquareBody(50, 50, 10), createSquareBody(400, 300, 200) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 13
        , Config{
            vector<Body>{ createSquareBody(50, 50, 10), createSquareBody(450, 300, 200) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 14
        , Config{
            vector<Body>{ createSquareBody(50, 50, 10), createSquareBody(400, 300, 300) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 15 
        , Config{
            vector<Body>{ createSquareBody(50, 50, 10), createSquareBody(450, 300, 300) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }

        //
        // Configs 16 - 23 have two squares in aBodies and a grid of 25x25 
        // squares in bBodies.  The left square is constant, but the right 
        // square grows and shifts in x.  Here the left square always intersects
        // with one body in the grid.
        //

        // 16
        , Config{
            vector<Body>{ createSquareBody(50, 50, 100), createSquareBody(400, 300, 10) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 17
        , Config{
            vector<Body>{ createSquareBody(50, 50, 100), createSquareBody(450, 300, 10) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 18 
        , Config{
            vector<Body>{ createSquareBody(50, 50, 100), createSquareBody(400, 300, 100) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 19
        , Config{
            vector<Body>{ createSquareBody(50, 50, 100), createSquareBody(450, 300, 100) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 20
        , Config{
            vector<Body>{ createSquareBody(50, 50, 100), createSquareBody(400, 300, 200) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 21
        , Config{
            vector<Body>{ createSquareBody(50, 50, 100), createSquareBody(450, 300, 200) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 22
        , Config{
            vector<Body>{ createSquareBody(50, 50, 100), createSquareBody(400, 300, 300) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }
        // 23
        , Config{
            vector<Body>{ createSquareBody(50, 50, 100), createSquareBody(450, 300, 300) },
            vector<Body>{ createSquaresOnGrid(5, 100, 5, 100, 20) }
        }


    };

    return configs;
}