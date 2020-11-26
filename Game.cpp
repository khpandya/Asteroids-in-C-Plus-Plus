#include "Game.h"
#include "collisions.h"

#include <sstream>
#include <iostream>
#include <array>
using namespace std;

Game::Game()
    : m_window(sf::VideoMode(800, 600), "A6", sf::Style::Titlebar | sf::Style::Close)
    , m_player{
         CartVec { 400, 300 }, CartVec { 0, 0 }, 0, 0, createPlayerTriFan(),
         Colour::Blue
    }
    , m_state{ State::PLAYING }
{
    m_asteroids.push_back(
        Body{ CartVec { 100, 100 }, CartVec { 0, 0 }, 0, 0, 50, 150,
        Colour::getRandomColour() }
    );

    m_asteroids.push_back(
        Body{ CartVec { 100, 300 }, CartVec { 0.001, 0 }, 0, -0.0002, 6, 50,
        Colour::getRandomColour() }
    );

    m_asteroids.push_back(
        Body{ CartVec { 500, 100 }, CartVec { 0, 0 }, 0, 0.0001, 15, 80,
        Colour::getRandomColour() }
    );

    m_asteroids.push_back(
        Body{ CartVec { 500, 100 }, CartVec { 0.01, 0.01 }, 0, 0.0001, 10, 80,
        Colour::getRandomColour(), false }
    );
}

void Game::loop()
{
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (m_state == State::PLAYING && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && m_bulletWait == 0) {
                    launchBullet();
                }
                if (event.key.code == sf::Keyboard::Up) {
                    m_player.applyThrust(0.02);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    m_player.adjustAngle(-0.3);
                }
                if (event.key.code == sf::Keyboard::Right) {
                    m_player.adjustAngle(0.3);
                }
            }
        }

        m_window.clear();
        updateTitle();

        handleCollisions();
        handleBullets();

        // Get a master list of all bodies, regardless of type.
        vector<Body*> bodies;
        for (Body& a : m_asteroids)
            bodies.push_back(&a);
        for (Body& b : m_bullets)
            bodies.push_back(&b);
        if (m_state == State::PLAYING)
            bodies.push_back(&m_player); // Add player last so it is drawn last

        applyPhysics(bodies);
        draw(bodies);

        m_window.display();
    }
}

void Game::launchBullet() 
{
    constexpr double bulletSpeed = 0.2;
    CartVec position = m_player.centre();
    CartVec velocity{
        bulletSpeed * cos(m_player.angle()),
        bulletSpeed * sin(m_player.angle()),
    };
    m_bullets.push_back(
        Body{ position, velocity, 0, 0.1, 15, 10, Colour::Red, false}
    );
    m_bulletWait = 200; // Wait this long before launching another.
}

void Game::updateTitle()
{
    stringstream ss;
    if (m_state == State::PLAYING)
        ss << "Asteroids: " << m_asteroids.size();
    else 
        ss << "GAME OVER!";
    m_window.setTitle(ss.str());
}

void Game::handleCollisions()
{
    bulletsOnAsteroids(m_bullets, m_asteroids);

    // Now check for collisions between the player and all asteroids.
    if (m_state == State::PLAYING) {
        vector<pair<Body, Body>> pairs = getCollidedPairs(vector<Body>{m_player}, m_asteroids);
        if (pairs.size() > 0) {
            m_state = State::GAME_OVER;
            cout << "GAME OVER!" << endl;

            // The player becomes asteroid fragments!
            if (m_player.canSplit()) {
                vector<Body> fragments = m_player.split();
                // Insert all asteroid fragments back into m_asteroids
                m_asteroids.insert(m_asteroids.end(), fragments.begin(), fragments.end());
            }
        }
    }
}

void Game::handleBullets()
{
    // Get rid of older bullets
    for (vector<Body>::iterator it = m_bullets.begin();
         it != m_bullets.end(); )
    {
        if (it->age() > 2000) {
            m_bullets.erase(it);
        } else {
            ++it;
        }
    }

    // Decrement wait time before next launch.
    if (m_bulletWait > 0) --m_bulletWait;

    // Give the bullets a flickering effect by randomizing their alpha channel.
    for (Body& b : m_bullets)
        b.setColour( b.colour().getWithRandomAlpha() );
}

void Game::applyPhysics(vector<Body*> bodies)
{
    sf::Vector2u size = m_window.getSize();

    for (Body* b : bodies) {
        b->update();

        vector<CartVec> vertices = b->vertexPositions();
        vertices.push_back(b->centre());

        // Check for collision with the world's boundaries.
        for (const CartVec& v : vertices) {
            if (v.x < 0) {
                b->horizontalCollision(-v.x);
                break;
            }
            if (v.x > size.x) {
                b->horizontalCollision(size.x - v.x);
                break;
            }
            if (v.y < 0) {
                b->verticalCollision(-v.y);
                break;
            }
            if (v.y > size.y) {
                b->verticalCollision(size.y - v.y);
                break;
            }
        }
    }
}

void Game::draw(vector<Body*> bodies)
{
    for (Body* b : bodies) {

        vector<CartVec> vertices = b->vertexPositions();
        CartVec centre = b->centre();

        CartVec lastV = vertices[0];
        int nverts = vertices.size();
        for (int i = 1; i < nverts; i++) {
            sf::VertexArray triangle(sf::Triangles, 3);

            triangle[0].position = sf::Vector2f(lastV.x, lastV.y);
            lastV = vertices[i];
            triangle[1].position = sf::Vector2f(lastV.x, lastV.y);
            triangle[2].position = sf::Vector2f(centre.x, centre.y);

            // Just so that we can distinguish between individual triangles, we
            // brighten one vertex by a small amount.
            Colour colour = b->colour();
            sf::Color c{colour.red, colour.green, colour.blue, colour.alpha};
            sf::Color brightened = c + sf::Color{20, 20, 20, 0};
            triangle[0].color = brightened;
            triangle[1].color = c;
            triangle[2].color = c;

            m_window.draw(triangle);
        }
    }
}

TriFan* Game::createPlayerTriFan()
{
    constexpr double bow = 30;
    constexpr double midbow = 15;
    constexpr double stern = 10;
    constexpr double tail = 12;
    constexpr double wingLength = 20;
    std::array<PolarVec, 12> vertexArray{
        PolarVec{0, bow},
        PolarVec{M_PI/4, midbow},
        PolarVec{M_PI/2, wingLength/2},
        PolarVec{M_PI/2, wingLength},
        PolarVec{3*M_PI/4, stern},
        PolarVec{3*M_PI/4, tail},
        PolarVec{-3*M_PI/4, tail},
        PolarVec{-3*M_PI/4, stern},
        PolarVec{-M_PI/2, wingLength},
        PolarVec{-M_PI/2, wingLength/2},
        PolarVec{-M_PI/4, midbow},
        PolarVec{0, bow}
    };
    return new TriFan{vertexArray.data(), vertexArray.size() };
}