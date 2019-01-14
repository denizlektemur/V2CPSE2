#include "rectangle.hpp"

rectangle::rectangle(sf::RenderWindow & window, sf::Vector2f location, sf::Vector2f size) :
	window{ window }
{
	rect.setPosition(location);
	rect.setSize(size);
}

void rectangle::draw() {
	window.draw(rect);
}

bool rectangle::contains(sf::Vector2f location) {
	return rect.getGlobalBounds().contains(location);
}

void rectangle::changeColor(sf::Color newColor) {
	color = newColor;
	rect.setFillColor(color);
}

sf::Color rectangle::getColor() {
	return color;
}