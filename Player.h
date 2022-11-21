#pragma once

#include "Vector2D.h"

namespace sf {
	class RenderWindow;
	class View;
	class Sprite;
}

class Player
{
private:
	static constexpr float speed = 2.f;
	vector2D location = vector2D(0, 0);

	sf::Texture textureL, textureD;
	sf::Sprite sprite;
public:
	Player();
	~Player();

	void draw(sf::RenderWindow& window);
	void inputs(sf::View& view);
};

