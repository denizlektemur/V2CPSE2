#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "rectangle.hpp"
#include <iostream>

class Game {
private:
	sf::Color player1 = sf::Color::Blue;
	sf::Color player2 = sf::Color::Red;
	sf::Color neutral = sf::Color::White;
	std::vector<rectangle> squares;
	std::vector<int> moves;
	sf::Color turn = player1;
	bool won = false;
public:
	Game(sf::RenderWindow & window);
	void draw_board();
	void make_move(sf::Vector2f position);
	bool check_line(rectangle a, rectangle b, rectangle c);
	bool check_win();
	void print_board();
	void undo_move();
};

