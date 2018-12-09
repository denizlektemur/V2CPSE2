#include "line.hpp"

line::line(sf::Vector2f position, float length, float rotation, sf::Color color) :
	position(position),
	length(length),
	rotation(rotation),
	color(color)
{
	rect.setPosition(sf::Vector2f(position));
	rect.setSize(sf::Vector2f((float)length, (float)thickness));
	rect.setRotation((float)rotation);
	rect.setFillColor(color);
}

void line::draw(sf::RenderWindow & window) {
	window.draw(rect);
}

void line::set_position(sf::Vector2f new_position) {
	position = new_position;
	rect.setPosition(sf::Vector2f(position));
}

sf::FloatRect line::get_hitbox() {
	return rect.getGlobalBounds();
}

sf::Color line::get_color() {
	return color;
}

sf::Vector2f line::get_position() {
	return position;
}

sf::Vector2f line::get_size() {
	return sf::Vector2f{ length, rotation };
}

std::string line::get_name() {
	return name;
}

std::string line::get_path() {
	return "None";
}

sf::Color line::string_to_color(std::string color) {
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
