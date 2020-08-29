#include <SFML/Graphics.hpp>
#include "constants.h"
#include "World.h"
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    Player player(150, 150);
    World world;

    sf::Clock clock;
    sf::Time curtime = clock.getElapsedTime();
    sf::Time prevtime = clock.getElapsedTime();
    sf::Time deltatime = curtime - prevtime;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            if(event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::W: player.velocity += sf::Vector2f(0, -1); break;
                    case sf::Keyboard::A: player.velocity += sf::Vector2f(-1, 0); break;
                    case sf::Keyboard::S: player.velocity += sf::Vector2f(0,  1); break;
                    case sf::Keyboard::D: player.velocity += sf::Vector2f(1,  0); break;
                    case sf::Keyboard::F1: {
                        sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(16, 16));
                        rect->setPosition(player.pos);
                        world.AddShape(rect);
                    }; break;
                    case sf::Keyboard::F2: {
                        sf::CircleShape* circle = new sf::CircleShape(12);
                        circle->setPosition(player.pos);
                        world.AddShape(circle);
                    }; break;
                }
            }
        }

        curtime = clock.getElapsedTime();
        deltatime += curtime - prevtime;
        prevtime = curtime;

        while(deltatime > sf::milliseconds(1000 / 60)) {
            player.update();
            deltatime -= sf::milliseconds(1000 / 60);
        }

        window.clear();

        world.draw(window);
        player.draw(window);
        //window.draw(player);
        window.display();
    }

    return 0;
}