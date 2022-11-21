#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player()
{
	if (!textureD.loadFromFile("textures/textureD.png"))
		return;
	sprite = sf::Sprite(textureD);

	if (!textureL.loadFromFile("textures/textureL.png"))
		return;
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow& window)
{
	sprite.setScale(0.2, 0.2);
	sprite.setPosition(location.x, location.y);
	window.draw(sprite);
}

void Player::inputs(sf::View& view)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		location.x += speed;
		view.move(2, 0);
		sprite.setTexture(textureD);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		location.x -= speed;
		view.move(-2, 0);
		sprite.setTexture(textureL);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		location.y -= speed;
		view.move(0, -2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		location.y += speed;
		view.move(0, 2);
	}
}
