#pragma once

#include "SFML/Graphics.hpp"
#include "drawable.hpp"

class ball : public drawable {
private:
	float size;
	sf::Vector2f speed = { 10, 10 };
	sf::Vector2f location;
	sf::CircleShape circle;
	sf::RenderWindow & window;
	const char * name;
	sf::RectangleShape top_and_bottom;
	sf::RectangleShape left_and_right;
public:
	ball( const char * name, sf::RenderWindow & window, sf::Vector2f location, float = 30 );
	void draw() override;
	void update() override;
	sf::Vector2f getLocation() override;
	sf::Vector2f getSize() override;
	const char * getName() override;
	void changeSpeed(sf::Vector2f speedChange);
	void setLocation(sf::Vector2f newLocation);
	void checkCollision(drawable * other);
	void move_back();
	sf::FloatRect getHitbox() override;
};

