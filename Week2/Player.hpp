#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>

class player {
public:

	player(sf::Vector2f position, sf::Vector2f size = sf::Vector2f{ 100, 100 });

	void draw(sf::RenderWindow & window);

	void move(sf::Vector2f delta);

	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);

	sf::FloatRect getTopHitbox();
	sf::FloatRect getBottomHitbox();
	sf::FloatRect getLeftHitbox();
	sf::FloatRect getRightHitbox();

	float getTop();
	float getBottom();
	float getLeft();
	float getRight();

private:
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	sf::Vector2f size;
};
#endif