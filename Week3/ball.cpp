#include "ball.hpp"

ball::ball(sf::Vector2f position, float size, sf::Color color):
	position(position),
	size(size),
	color(color)
{
	circle.setPosition(position);
	circle.setRadius(size);
	circle.setFillColor(color);
}

void ball::draw(sf::RenderWindow & window) {
	window.draw(circle);
}

void ball::set_position(sf::Vector2f new_position) {
	position = new_position;
	circle.setPosition(sf::Vector2f(position));
}

sf::FloatRect ball::get_hitbox() {
	return circle.getGlobalBounds();
}

sf::Color ball::get_color() {
	return color;
}

sf::Vector2f ball::get_position() {
	return position;
}

sf::Vector2f ball::get_size() {
	return sf::Vector2f(size, size);
}

std::string ball::get_name() {
	return name;
}

std::string ball::get_path() {
	return "None";
}

sf::Color ball::string_to_color(std::string color) {
	if (color == "RED") {
		return sf::Color::Red;
	}
	else if (color == "BLUE") {
		return sf::Color::Blue;
	}
	else if (color == "GREEN") {
		return sf::Color::Green;
	}
	else if (color == "BLACK") {
		return sf::Color::Black;
	}
	else if (color == "WHITE") {
		return sf::Color::White;
	}
	else {
		return sf::Color::White;
	}
}