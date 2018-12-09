#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "exceptions.hpp"

std::ifstream & operator>>(std::ifstream & input, sf::Color & rhs) {
	std::string s;
	input >> s;
	const struct { const char * name; sf::Color color; } colors[]{
		{ "yellow", sf::Color::Yellow },
		{ "red",    sf::Color::Red },
		{ "blue", sf::Color::Blue},
		{ "black", sf::Color::Black},
		{ "green", sf::Color::Green },
		{ "white", sf::Color::White},
		{ "magenta", sf::Color::Magenta },
		{ "cyan", sf::Color::Cyan }
	};
	for (auto const & color : colors) {
		if (color.name == s) {
			rhs = color.color;
			return input;
		}
	}
	if (s == "") {
		throw end_of_file();
	}
	throw unknown_color(s);
}


std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs) {
	char c;
	if (!(input >> c)) { throw end_of_file(); }
	if (c != '(') { throw invalid_position(c); }

	if (!(input >> rhs.x)) { throw invalid_position(c); }

	if (!(input >> c)) { throw invalid_position(c); }

	if (!(input >> rhs.y)) { throw invalid_position(c); }

	if (!(input >> c)) { throw invalid_position(c); }
	if (c != ')') { throw invalid_position(c); }

	return input;
}

std::ofstream & operator<<(std::ofstream & input, const sf::Vector2f & rhs) {

	input << '(' << int(rhs.x) << ',' << int(rhs.y) << ')';
	return input;
}

std::ofstream & operator<<(std::ofstream & input, const sf::Color & rhs) {

	const struct { const char * name; sf::Color color; } colors[]{
		{ "yellow", sf::Color::Yellow },
		{ "red",    sf::Color::Red },
		{ "blue", sf::Color::Blue },
		{ "black", sf::Color::Black },
		{ "green", sf::Color::Green },
		{ "white", sf::Color::White },
		{ "magenta", sf::Color::Magenta },
		{ "cyan", sf::Color::Cyan }
	};
	for (auto const & color : colors) {
		if (color.color == rhs) {
			input << color.name << " ";
			return input;
		}
	}
	throw unknown_color();
}