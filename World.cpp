#include "World.h"

World::World() {}

void World::draw(sf::RenderTarget& window) {
	for(int i = 0; i < shapes.size(); i++) {
		window.draw(*shapes[i]);
	}
}

void World::AddShape(sf::Shape* shape) {
	shapes.push_back(shape);
}