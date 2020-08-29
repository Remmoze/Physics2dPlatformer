#include "constants.h"
#include "Player.h"

void Player::teleport(int x, int y) {
	pos.x = x;
	pos.y = y;
	image.setPosition(pos);
}

void Player::move(int dx, int dy) {
	pos += sf::Vector2f(dx * 16.0, dy * 16.0);
	//image.setPosition(pos);
}

Player::Player(int x, int y) {
	image = sf::CircleShape(16 / 2, 64);
	image.setFillColor(sf::Color(254, 220, 86));
	image.setOutlineThickness(1);
	image.setOutlineColor(sf::Color(196, 145, 2));

	Player::teleport(x, y);
}

void Player::draw(sf::RenderTarget& window) {
	image.setPosition(pos);
	window.draw(image);
}

sf::Vector2f graivty = sf::Vector2f(0, 0.5);
void Player::update() {
	velocity += graivty;
	pos += velocity;
}