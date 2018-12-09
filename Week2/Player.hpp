#pragma once

#include "drawable.hpp"

class player : public drawable {
private:
	sf::RenderWindow & window;
	sf::RectangleShape rect;
	sf::Vector2f location;
	sf::Vector2f size;
	const char * name;
public:
	player(const char * name, sf::RenderWindow & window, sf::Vector2f location, sf::Vector2f = sf::Vector2f{ 400, 20 });
	void draw() override;
	void update() override;
	const char * getName() override;
	sf::Vector2f getLocation() override;
	sf::Vector2f getSize() override;
	void move(sf::Vector2f delta);
	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);
	sf::FloatRect getHitbox() override;
};