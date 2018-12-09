#pragma once

#include "SFML/Graphics.hpp"
#include "drawable.hpp"
#include <string>

class line : public drawable {
private:
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::Color color;
	float rotation;
	float thickness = 10;
	float length;
	std::string name = "LINE";
public:
	line(sf::Vector2f position, float length, float rotation, sf::Color color);
	void draw(sf::RenderWindow & window) override;
	void set_position(sf::Vector2f new_position) override;
	sf::FloatRect get_hitbox() override;
	sf::Color get_color() override;
	sf::Vector2f get_position() override;
	sf::Vector2f get_size() override;
	std::string get_name() override;
	sf::Color string_to_color(std::string);
	std::string get_path() override;
};

