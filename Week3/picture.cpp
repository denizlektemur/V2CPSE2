#include "picture.hpp"

picture::picture(sf::Vector2f position, sf::Vector2f size, std::string file_name) :
	position(position),
	size(size),
	file_name(file_name)
{
	texture.loadFromFile(file_name, sf::IntRect(sf::Vector2i{ 0, 0 }, sf::Vector2i{ size }));
	sprite.setTexture(texture, true);
	sprite.setPosition(sf::Vector2f(position));
	//sprite.setTextureRect(sf::IntRect(position, size));
}

void picture::draw(sf::RenderWindow & window) {
	window.draw(sprite);
}

void picture::set_position(sf::Vector2f new_position) {
	position = new_position;
	sprite.setPosition(sf::Vector2f(position));
}

sf::FloatRect picture::get_hitbox() {
	return sprite.getGlobalBounds();
}

sf::Color picture::get_color() {
	return sf::Color::White;
}

sf::Vector2f picture::get_position() {
	return position;
}

sf::Vector2f picture::get_size() {
	return size;
}

std::string picture::get_name() {
	return name;
}

std::string picture::get_path() {
	return file_name;
}