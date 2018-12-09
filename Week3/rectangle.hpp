#pragma once

#include "SFML/Graphics.hpp"
#include "drawable.hpp"
#include <string>

class rectangle : public drawable {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Color color;
	std::string name;
public:
	rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	void draw(sf::RenderWindow & window) override;
	void set_position(sf::Vector2f new_position) override;
	sf::FloatRect get_hitbox() override;
	sf::Color get_color() override;
	sf::Vector2f get_position() override;
	sf::Vector2f get_size() override;
	sf::Color string_to_color(std::string);
	std::string get_name() override;
	std::string get_path() override;
};

