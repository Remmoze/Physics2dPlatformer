#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

class World
{
public:
	int Width;
	int Height;
	int* grid;

	World(int width, int height);

	void draw(sf::RenderTarget& window);

	void placeBlock(int type, int x, int y);

};

