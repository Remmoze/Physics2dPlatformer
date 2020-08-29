#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	sf::Vector2f pos;
	void teleport(int x, int y);
	void move(int dx, int dy);

	Player(int x, int y);

	void draw(sf::RenderTarget& window);

private:
	sf::CircleShape image;
};

