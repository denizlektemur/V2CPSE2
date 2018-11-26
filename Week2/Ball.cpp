#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(sf::Vector2f position, float size) :
	position{ position },
	size{ size }
	{
		circle.setRadius(size);
		circle.setPosition(position);
	}

void ball::draw(sf::RenderWindow & window) {
	circle.setPosition(position);
	circle.setRadius(size);
	window.draw(circle);
}

void ball::move(sf::Vector2f delta) {
	position += delta;
}

void ball::setX(float xValue) {
	position.x = xValue;
}

void ball::setY(float yValue) {
	position.y = yValue;
}

float ball::getX() {
	return position.x;
}

float ball::getY() {
	return position.y;
}

sf::FloatRect ball::getHitbox() {
	return circle.getGlobalBounds();
}