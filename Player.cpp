#include "constants.h"
#include "Player.h"

void Player::teleport(int x, int y) {
	pos.x = x;
	pos.y = y;
	image.setPosition(pos);
}

void Player::move(int dx, int dy) {
	pos += sf::Vector2f(dx, dy) * BlockSize;
	image.setPosition(pos);
}

Player::Player(int x, int y) {
	image = sf::CircleShape(BlockSize/2, 64);
	image.setFillColor(sf::Color(254, 220, 86));
	image.setOutlineThickness(1);
	image.setOutlineColor(sf::Color(196, 145, 2));

	Player::teleport(x, y);
}

void Player::draw(sf::RenderTarget& window) {
	window.draw(image);
}