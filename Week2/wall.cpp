#include "wall.hpp"

wall::wall(const char * name, sf::RenderWindow & window, sf::Vector2f location, sf::Vector2f size):
	name(name),
	window(window),
	location(location),
	size(size)
{
	rect.setPosition(location);
	rect.setSize(size);
}

void wall::draw() {
	window.draw(rect);
}

void wall ::update() {
	rect.setPosition(location);
}

sf::Vector2f wall::getLocation() {
	return location;
}

sf::Vector2f wall::getSize() {
	return size;
}

const char * wall::getName() {
	return name;
}

sf::FloatRect wall::getHitbox() {
	return rect.getGlobalBounds();
}
