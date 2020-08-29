#include "World.h"

World::World(int width = 25, int height = 25) {
	Width = width;
	Height = height;
	grid = new int[width * height];
}

void World::placeBlock(int type, int x, int y) {
	grid[y * Width + x] = type;
}

void World::draw(sf::RenderTarget& window) {
	sf::RectangleShape block(VectorBlock);
	block.setFillColor(sf::Color::Green);
	for(int y = 0; y < Height; y++) {
		for(int x = 0; x < Width; x++) {
			if(grid[y * Width + x] == 1) {
				block.setPosition(x * BlockSize, y * BlockSize);
				window.draw(block);
			}
		}
	}
}