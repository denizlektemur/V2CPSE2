#pragma once

#include "SFML/Graphics.hpp"

class drawable {
public:
	virtual void draw() {};
	virtual void update() {};
	virtual sf::Vector2f getLocation() = 0;
	virtual sf::Vector2f getSize() = 0;
	virtual const char * getName() = 0;
	virtual sf::FloatRect getHitbox() = 0;
};
