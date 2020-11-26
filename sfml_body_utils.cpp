#include "body_utils.h"
#include <SFML/Graphics.hpp>
using namespace A6;

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * Just to visualize various sets of bodies created by the functions in
 * body_utils.h.
 */
class Vis {
public:
    Vis(Config config, int index)
        : m_window(sf::VideoMode(800, 600), std::to_string(index))
    {
        ostringstream oss;
        oss << "Config_" << index << ".png";
        m_filename = oss.str();

        for (Body& x : config.bBodies) {
            x.setColour(Colour{0, 0, 255, 127});
            m_bodies.push_back(x);
        }

        for (Body& x : config.aBodies) {
            x.setColour(Colour{255, 0, 0, 127});
            m_bodies.push_back(x);
        }

    }

    void loop()
    {
        while (m_window.isOpen()) {
            sf::Event event;
            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) m_window.close();
            }

            m_window.clear();
            draw();
            m_window.display();

/*
sf::Texture texture;
texture.create(m_window.getSize().x, m_window.getSize().y);
texture.update(m_window);
if (texture.copyToImage().saveToFile(m_filename))
{
    std::cout << "screenshot saved to " << m_filename << std::endl;
}
*/
        }
    }

private:
    void draw()
    {
        for (const Body& b : m_bodies) {
            vector<CartVec> vertices = b.vertexPositions();
            CartVec centre = b.centre();

            CartVec lastV = vertices[0];
            int nverts = vertices.size();
            for (int i = 1; i < nverts; i++) {
                sf::VertexArray triangle(sf::Triangles, 3);

                triangle[0].position = sf::Vector2f(lastV.x, lastV.y);
                lastV = vertices[i];
                triangle[1].position = sf::Vector2f(lastV.x, lastV.y);
                triangle[2].position = sf::Vector2f(centre.x, centre.y);

                Colour colour = b.colour();
                sf::Color c { colour.red, colour.green, colour.blue, colour.alpha };
                sf::Color brightened = c + sf::Color { 20, 20, 20, 0 };
                triangle[0].color = brightened;
                triangle[1].color = c;
                triangle[2].color = c;

                m_window.draw(triangle);
            }
        }
    }
    sf::RenderWindow m_window;
    string m_filename;
    vector<Body> m_bodies;
};

int main()
{
    vector<Config> configs = allConfigs();
    for (int i=0; i < configs.size(); ++i) {
        Vis v{configs[i], i};
        v.loop();
    }
    return 0;
}