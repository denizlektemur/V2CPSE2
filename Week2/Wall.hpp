#pragma once

#include "SFML/Graphics.hpp"
#include "drawable.hpp"

class wall : public drawable {
private:
	sf::RenderWindow & window;
	sf::Vector2f location;
	sf::Vector2f size;
	sf::RectangleShape rect;
	const char * name;
public:
	wall(const char * name, sf::RenderWindow & window, sf::Vector2f location, sf::Vector2f size);
	void draw() override;
	void update() override;
	sf::Vector2f getLocation() override;
	sf::Vector2f getSize() override;
	const char * getName() override;
	sf::FloatRect getHitbox() override;
};

