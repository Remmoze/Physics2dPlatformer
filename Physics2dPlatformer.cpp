#include <SFML/Graphics.hpp>
#include "constants.h"
#include "World.h"
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    Player player(0, 0);
    World world(25, 25);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            if(event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::W: player.move(0, -1); break;
                    case sf::Keyboard::A: player.move(-1, 0); break;
                    case sf::Keyboard::S: player.move(0,  1); break;
                    case sf::Keyboard::D: player.move(1,  0); break;
                    case sf::Keyboard::E: {
                        world.placeBlock(1, player.pos.x/BlockSize, player.pos.y / BlockSize);
                    }
                }
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                world.placeBlock(event.mouseButton.button == sf::Mouse::Left, event.mouseButton.x / BlockSize, event.mouseButton.y / BlockSize);
            }
        }

        window.clear();

        world.draw(window);
        player.draw(window);
        //window.draw(player);
        window.display();
    }

    return 0;
}