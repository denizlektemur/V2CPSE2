#include "ball.hpp"
#include <iostream>

ball::ball(const char * name, sf::RenderWindow & window, sf::Vector2f location, float size):
	name(name),
	location(location),
	size(size),
	window(window)
{
	circle.setPosition(location);
	circle.setRadius(size);
	top_and_bottom.setPosition(sf::Vector2f{ location.x + (size / 2), location.y });
	top_and_bottom.setSize(sf::Vector2f{ size, (size * 2) });
	left_and_right.setPosition(sf::Vector2f{ location.x, location.y + (size / 2) });
	left_and_right.setSize(sf::Vector2f{ (size * 2), size });
}

void ball::draw() {
	window.draw(circle);
}

void ball::update() {
	location += speed;
	circle.setPosition(location);
	top_and_bottom.setPosition(sf::Vector2f{ location.x + (size / 2), location.y });
	left_and_right.setPosition(sf::Vector2f{ location.x, location.y + (size / 2) });
}

void ball::move_back() {
	location -= speed;
	circle.setPosition(location);
	top_and_bottom.setPosition(sf::Vector2f{ location.x + (size / 2), location.y });
	left_and_right.setPosition(sf::Vector2f{ location.x, location.y + (size / 2) });
}

sf::Vector2f ball::getLocation() {
	return location;
}

sf::Vector2f ball::getSize() {
	return sf::Vector2f{ size, size };
}

const char * ball::getName() {
	return name;
}

void ball::changeSpeed(sf::Vector2f speedChange) {
	speed.x *= speedChange.x;
	speed.y *= speedChange.y;
}

void ball::setLocation(sf::Vector2f newLocation) {
	location = newLocation;
	top_and_bottom.setPosition(sf::Vector2f{ location.x + (size / 2), location.y });
	left_and_right.setPosition(sf::Vector2f{ location.x, location.y + (size / 2) });
}

sf::FloatRect ball::getHitbox() {
	return circle.getGlobalBounds();
}

void ball::checkCollision(drawable * other) {

	if (this != other) {
		if (getHitbox().intersects(other->getHitbox())) {
			// top and bottom
			if (top_and_bottom.getGlobalBounds().intersects(other->getHitbox())) {
				move_back();
				changeSpeed(sf::Vector2f{ 1, -1 });
			}
			// left and right
			else if (left_and_right.getGlobalBounds().intersects(other->getHitbox())) {
				move_back();
				changeSpeed(sf::Vector2f{ -1, 1 });
			}
		}
	}
}
