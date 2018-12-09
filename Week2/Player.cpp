#include "player.hpp"

player::player(const char * name, sf::RenderWindow & window, sf::Vector2f location, sf::Vector2f size):
	name(name),
	window(window),
	location(location),
	size(size)
{
	rect.setPosition(location);
	rect.setSize(size);
}

void player::draw() {
	window.draw(rect);
}

void player::update() {
	rect.setPosition(location);
}

const char * player::getName() {
	return name;
}

sf::Vector2f player::getLocation() {
	return location;
}

sf::Vector2f player::getSize() {
	return size;
}

void player::move(sf::Vector2f delta) {
	location += delta;
}

void player::jump(sf::Vector2f target) {
	location = target;
}

void player::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	));
}

sf::FloatRect player::getHitbox() {
	return rect.getGlobalBounds();
}