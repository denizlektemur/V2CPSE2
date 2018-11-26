#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>

class ball {
public:

	ball(sf::Vector2f position, float size = 30.0);

	void draw(sf::RenderWindow & window);
	void move(sf::Vector2f delta);
	void setX(float xValue);
	void setY(float yValue);
	float getX();
	float getY();

	sf::FloatRect getHitbox();

private:
	sf::CircleShape circle;
	sf::Vector2f position;
	float size;
};
#endif