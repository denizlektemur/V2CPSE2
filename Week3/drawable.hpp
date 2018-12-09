#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class drawable {
public:
	virtual void draw(sf::RenderWindow & window) {};
	virtual void set_position(sf::Vector2f new_position) {};
	virtual sf::FloatRect get_hitbox() = 0;
	virtual sf::Color get_color() = 0;
	virtual sf::Vector2f get_position() = 0;
	virtual sf::Vector2f get_size() = 0;
	virtual std::string get_name() = 0;
	virtual std::string get_path() = 0;
};