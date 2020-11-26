#if !defined(GAME_H)
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Body.h"
#include "collisions.h"

using namespace A6;

/**
 * An asteroids clone, where the asteroids are represented by triangle fans
 * that are split apart by the player's bullets.
 * 
 * Controls: Left/right arrows to rotate.  Up to apply thrust.  Space to shoot.
 * 
 * @author Andrew Vardy
 */
class Game {
public:

    /**
     * Possible game states.  Could potentially introduce others (e.g. PAUSED).
     */
    enum class State { PLAYING, GAME_OVER };

    /**
     * Construct the Game, including opening the window and creating
     * any entities that will populate the world.
     */
    Game();

    /**
     * The main game loop.  This function will not return until the user has
     * closed the window.
     */
    void loop();

private:

    /**
     * Launch a bullet (meaning add a bullet at the player's location.
     */
    void launchBullet();

    /**
     * Update the window's title to show some statistics.
     */
    void updateTitle();

    /**
     * Handle collisions between all three types of bodies.
     */
    void handleCollisions();

    /**
     * Handle removal of bodies that have died of old age.
     */
    void handleBullets();

    /**
     * Modified the velocities of entities to account for any collisions.
     * Update all entity positions.
     */
    void applyPhysics(vector<Body*> bodies);

    /**
     * Draw all entities.
     */
    void draw(vector<Body*> bodies);

    /**
     * Put together a special TriFan for the player's body.
     */
    TriFan* createPlayerTriFan();

    sf::RenderWindow m_window;

    // The characters: player, asteroids and bullets.
    Body m_player;
    vector<Body> m_asteroids;
    vector<Body> m_bullets;

    State m_state;

    // If this is positive, then we need to wait before launching another bullet.
    int m_bulletWait = 0;
};

#endif // !defined(GAME_H)