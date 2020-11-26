#include "Game.h"
#include <iostream>
using std::cout;
using namespace A6;

int main()
{
    cout << "Controls: Left/right arrows to rotate.  "
         << "Up to apply thrust.  Space to shoot.\n";
    Game g;
    g.loop();
    return 0;
}