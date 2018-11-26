#include <SFML/Graphics.hpp>
#include "player.hpp"

player::player(sf::Vector2f position, sf::Vector2f size) :
	position{ position },
	size{ size }
	{
		rectangle.setPosition(position);
		rectangle.setSize(size);
	}

void player::draw(sf::RenderWindow & window) {
	rectangle.setPosition(position);
	rectangle.setSize(size);
	window.draw(rectangle);
}

void player::move(sf::Vector2f delta) {
	position += delta;
}

void player::jump(sf::Vector2f target) {
	position = target;
}

void player::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	));
}

sf::FloatRect player::getTopHitbox() {
	return sf::FloatRect{ position.x + 1, position.y, size.x - 2, 1 };
}

sf::FloatRect player::getBottomHitbox() {
	return sf::FloatRect{ position.x + 1, position.y + size.y - 1, size.x - 2, 1 };
}

sf::FloatRect player::getLeftHitbox() {
	return sf::FloatRect{ position.x, position.y + 1, 1, size.y - 2 };
}

sf::FloatRect player::getRightHitbox() {
	return sf::FloatRect{ position.x + size.x - 1, position.y + 1, 1, size.y - 2 };
}

float player::getTop() {
	return position.y;
}

float player::getBottom() {
	return position.y + size.y;
}

float player::getLeft() {
	return position.x;
}

float player::getRight() {
	return position.x + size.x;
}