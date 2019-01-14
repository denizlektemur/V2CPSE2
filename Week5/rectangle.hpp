#pragma once

#include "SFML/Graphics.hpp"

class rectangle {
private:
	sf::RenderWindow & window;
	sf::RectangleShape rect;
	sf::Color color;
public:
	rectangle(sf::RenderWindow & window, sf::Vector2f location, sf::Vector2f size);
	void draw();
	bool contains(sf::Vector2f location);
	void changeColor(sf::Color color);
	sf::Color getColor();
};

