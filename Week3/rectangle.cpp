#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	position(position),
	size(size),
	color(color)
{
	rect.setPosition(sf::Vector2f(position));
	rect.setSize(sf::Vector2f(size));
	rect.setFillColor(color);
}

void rectangle::draw(sf::RenderWindow & window) {
	window.draw(rect);
}

void rectangle::set_position(sf::Vector2f new_position) {
	position = new_position;
	rect.setPosition(sf::Vector2f(position));
}

sf::FloatRect rectangle::get_hitbox() {
	return rect.getGlobalBounds();
}

sf::Color rectangle::get_color() {
	return color;
}

sf::Vector2f rectangle::get_position() {
	return position;
}

sf::Vector2f rectangle::get_size() {
	return size;
}

std::string rectangle::get_path() {
	return "None";
}

sf::Color rectangle::string_to_color(std::string color) {
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

std::string rectangle::get_name() {
	return name;
}