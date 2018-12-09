#pragma once

#include "SFML/Graphics.hpp"
#include "drawable.hpp"
#include <string>

class picture : public drawable {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	std::string file_name;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string name;
public:
	picture(sf::Vector2f position, sf::Vector2f size, std::string file_name);
	void draw(sf::RenderWindow & window) override;
	void set_position(sf::Vector2f new_position) override;
	sf::FloatRect get_hitbox() override;
	sf::Color get_color() override;
	sf::Vector2f get_position() override;
	sf::Vector2f get_size() override;
	std::string get_name() override;
	std::string get_path() override;
};