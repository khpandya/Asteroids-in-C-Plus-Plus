/**
 * Tests for the bulletsOnAsteroids function declared in collisions.h, 
 * utilizing the Catch2 unit testing framework supplied in catch.h.
 */

#define CATCH_CONFIG_MAIN
#include "catch.h"

#include "collisions.h"
#include "body_utils.h"
#include <iostream>
using namespace std;
using namespace A6;

using Catch::Matchers::VectorContains;

vector<Config> configs = allConfigs();

TEST_CASE("Config 0", "[bulletsOnAsteroids]")
{
    Config &config = configs[0];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 26 );
}

TEST_CASE("Config 1", "[bulletsOnAsteroids]")
{
    Config &config = configs[1];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 25 );
}

TEST_CASE("Config 2", "[bulletsOnAsteroids]")
{
    Config &config = configs[2];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 26 );
}

TEST_CASE("Config 3", "[bulletsOnAsteroids]")
{
    Config &config = configs[3];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 27 );
}

TEST_CASE("Config 4", "[bulletsOnAsteroids]")
{
    Config &config = configs[4];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 34 );
}

TEST_CASE("Config 5", "[bulletsOnAsteroids]")
{
    Config &config = configs[5];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 31 );
}

TEST_CASE("Config 6", "[bulletsOnAsteroids]")
{
    Config &config = configs[6];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 34 );
}

TEST_CASE("Config 7", "[bulletsOnAsteroids]")
{
    Config &config = configs[7];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 34 );
}

TEST_CASE("Config 8", "[bulletsOnAsteroids]")
{
    Config &config = configs[8];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 26 );
}

TEST_CASE("Config 9", "[bulletsOnAsteroids]")
{
    Config &config = configs[9];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 2 );
    CHECK( config.bBodies.size() == 25 );
}

TEST_CASE("Config 10", "[bulletsOnAsteroids]")
{
    Config &config = configs[10];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 26 );
}

TEST_CASE("Config 11", "[bulletsOnAsteroids]")
{
    Config &config = configs[11];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 27 );
}

TEST_CASE("Config 12", "[bulletsOnAsteroids]")
{
    Config &config = configs[12];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 34 );
}

TEST_CASE("Config 13", "[bulletsOnAsteroids]")
{
    Config &config = configs[13];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 31 );
}

TEST_CASE("Config 14", "[bulletsOnAsteroids]")
{
    Config &config = configs[14];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 34 );
}

TEST_CASE("Config 15", "[bulletsOnAsteroids]")
{
    Config &config = configs[15];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 34 );
}

TEST_CASE("Config 16", "[bulletsOnAsteroids]")
{
    Config &config = configs[16];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 27 );
}

TEST_CASE("Config 17", "[bulletsOnAsteroids]")
{
    Config &config = configs[17];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 1 );
    CHECK( config.bBodies.size() == 26 );
}

TEST_CASE("Config 18", "[bulletsOnAsteroids]")
{
    Config &config = configs[18];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 27 );
}

TEST_CASE("Config 19", "[bulletsOnAsteroids]")
{
    Config &config = configs[19];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 28 );
}

TEST_CASE("Config 20", "[bulletsOnAsteroids]")
{
    Config &config = configs[20];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 35 );
}

TEST_CASE("Config 21", "[bulletsOnAsteroids]")
{
    Config &config = configs[21];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 32 );
}

TEST_CASE("Config 22", "[bulletsOnAsteroids]")
{
    Config &config = configs[22];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 35 );
}

TEST_CASE("Config 23", "[bulletsOnAsteroids]")
{
    Config &config = configs[23];
    bulletsOnAsteroids(config.aBodies, config.bBodies);
    CHECK( config.aBodies.size() == 0 );
    CHECK( config.bBodies.size() == 35 );
}
