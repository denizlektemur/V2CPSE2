#include <SFML/Graphics.hpp>
#include "Wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size) :
	position{ position },
	size{ size }
	{
		rectangle.setPosition(position);
		rectangle.setSize(size);
	}

void wall::draw(sf::RenderWindow & window) const {
	window.draw(rectangle);
}

sf::FloatRect wall::getHitbox() {
	return rectangle.getGlobalBounds();
}