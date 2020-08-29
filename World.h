#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

class World
{
public:
	World();

	void AddShape(sf::Shape* shape);
	void draw(sf::RenderTarget& window);
private:
	std::vector<sf::Shape*> shapes;
};

