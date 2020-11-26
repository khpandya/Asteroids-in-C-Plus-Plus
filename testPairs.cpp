/**
 * Tests for the getCollidedPairs function declared in collisions.h, 
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

TEST_CASE("Config 0", "[getCollidedPairs]")
{
    Config &config = configs[0];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 1 );
    CHECK( pairs[0].first == config.aBodies[0] );
    CHECK( pairs[0].second == config.bBodies[13] );
}

TEST_CASE("Config 1", "[getCollidedPairs]")
{
    Config &config = configs[1];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 0 );
}

TEST_CASE("Config 2", "[getCollidedPairs]")
{
    Config &config = configs[2];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 1 );
    CHECK( pairs[0].first == config.aBodies[0] );
    CHECK( pairs[0].second == config.bBodies[13] );
}

TEST_CASE("Config 3", "[getCollidedPairs]")
{
    Config &config = configs[3];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 2 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[14]}) );
}

TEST_CASE("Config 4", "[getCollidedPairs]")
{
    Config &config = configs[4];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 9 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[19]}) );
}

TEST_CASE("Config 5", "[getCollidedPairs]")
{
    Config &config = configs[5];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 6 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[19]}) );
}

TEST_CASE("Config 6", "[getCollidedPairs]")
{
    Config &config = configs[6];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 9 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[19]}) );
}

TEST_CASE("Config 7", "[getCollidedPairs]")
{
    Config &config = configs[7];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 9 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[19]}) );
}

TEST_CASE("Config 8", "[getCollidedPairs]")
{
    Config &config = configs[8];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 1 );
    CHECK( pairs[0].first == config.aBodies[1] );
    CHECK( pairs[0].second == config.bBodies[13] );
}

TEST_CASE("Config 9", "[getCollidedPairs]")
{
    Config &config = configs[9];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 0 );
}

TEST_CASE("Config 10", "[getCollidedPairs]")
{
    Config &config = configs[10];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 1 );
    CHECK( pairs[0].first == config.aBodies[1] );
    CHECK( pairs[0].second == config.bBodies[13] );
}

TEST_CASE("Config 11", "[getCollidedPairs]")
{
    Config &config = configs[11];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 2 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
}

TEST_CASE("Config 12", "[getCollidedPairs]")
{
    Config &config = configs[12];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 9 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[19]}) );
}

TEST_CASE("Config 13", "[getCollidedPairs]")
{
    Config &config = configs[13];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 6 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[19]}) );
}

TEST_CASE("Config 14", "[getCollidedPairs]")
{
    Config &config = configs[14];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 9 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[19]}) );
}

TEST_CASE("Config 15", "[getCollidedPairs]")
{
    Config &config = configs[15];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 9 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[19]}) );
}

TEST_CASE("Config 16", "[getCollidedPairs]")
{
    Config &config = configs[16];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 2 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[0]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
}

TEST_CASE("Config 17", "[getCollidedPairs]")
{
    Config &config = configs[17];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 1 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[0]}) );
}

TEST_CASE("Config 18", "[getCollidedPairs]")
{
    Config &config = configs[18];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 2 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[0]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
}

TEST_CASE("Config 19", "[getCollidedPairs]")
{
    Config &config = configs[19];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 3 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[0]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
}

TEST_CASE("Config 20", "[getCollidedPairs]")
{
    Config &config = configs[20];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 10 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[0]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[19]}) );
}

TEST_CASE("Config 21", "[getCollidedPairs]")
{
    Config &config = configs[21];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 7 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[0]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[19]}) );
}

TEST_CASE("Config 22", "[getCollidedPairs]")
{
    Config &config = configs[22];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 10 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[0]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[19]}) );
}

TEST_CASE("Config 23", "[getCollidedPairs]")
{
    Config &config = configs[23];
    vector<pair<Body, Body>> pairs = getCollidedPairs(config.aBodies, config.bBodies);
    CHECK( pairs.size() == 10 );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[0], config.bBodies[0]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[7]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[8]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[9]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[12]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[13]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[14]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[17]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[18]}) );
    REQUIRE_THAT( pairs, VectorContains(pair<Body, Body>{config.aBodies[1], config.bBodies[19]}) );
}
