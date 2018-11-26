#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>

class wall {
public:
	wall(sf::Vector2f position, sf::Vector2f size = sf::Vector2f{ 100, 20 });

	void draw(sf::RenderWindow & window) const;
	sf::FloatRect getHitbox();
private:
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	sf::Vector2f size;
};
#endif