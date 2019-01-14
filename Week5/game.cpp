#include "game.hpp"

Game::Game(sf::RenderWindow & window) {
	//rectangle rect1(window, sf::Vector2f(0, 0), sf::Vector2f(200, 200));
	//rectangle rect2(window, sf::Vector2f(220, 0), sf::Vector2f(200, 200));
	//rectangle rect3(window, sf::Vector2f(440, 0), sf::Vector2f(200, 200));
	//rectangle rect4(window, sf::Vector2f(0, 220), sf::Vector2f(200, 200));
	//rectangle rect5(window, sf::Vector2f(220, 220), sf::Vector2f(200, 200));
	//rectangle rect6(window, sf::Vector2f(440, 220), sf::Vector2f(200, 200));
	//rectangle rect7(window, sf::Vector2f(0, 440), sf::Vector2f(200, 200));
	//rectangle rect8(window, sf::Vector2f(220, 440), sf::Vector2f(200, 200));
	//rectangle rect9(window, sf::Vector2f(440, 440), sf::Vector2f(200, 200));
	//squares.push_back(rect1);
	//squares.push_back(rect2);
	//squares.push_back(rect3);
	//squares.push_back(rect4);
	//squares.push_back(rect5);
	//squares.push_back(rect6);
	//squares.push_back(rect7);
	//squares.push_back(rect8);
	//squares.push_back(rect9);
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j ++) {
			squares.push_back(rectangle(window, sf::Vector2f(float(j)*220, float(i)*220), sf::Vector2f(200, 200)));
		}
	}
	for (auto object : squares) {
		object.draw();
	}
	turn = player1;
}

void Game::draw_board() {
	for (auto object : squares) {
		object.draw();
	}
}

void Game::make_move(sf::Vector2f position) {
	for (unsigned int i = 0; i < squares.size(); i++) {
		if ( won == false && squares[i].getColor() != player1 && squares[i].getColor() != player2 && squares[i].contains(position)) {
			moves.push_back(i);
			squares[i].changeColor(turn);
			print_board();
			if (turn == player1) {
				turn = player2;
			}
			else {
				turn = player1;
			}
			if (check_win()) {
				won = true;
				if (turn == player1) {
					std::cout << "The winner is: Red\n";
				}
				else {
					std::cout << "The winner is: Blue\n";
				}
			}
			else if (moves.size() == 9) {
				std::cout << "Draw\n";
			}
		}
	}
}

bool Game::check_line(rectangle a, rectangle b, rectangle c) {
	if (a.getColor() == player1 || a.getColor() == player2) {
		if (a.getColor() == b.getColor() && a.getColor() == c.getColor()) {
			return true;
		}
	}
	return false;
}

bool Game::check_win() {
	if (check_line(squares[0], squares[1], squares[2]) ||
		check_line(squares[3], squares[4], squares[5]) ||
		check_line(squares[6], squares[7], squares[8]) ||
		check_line(squares[0], squares[3], squares[6]) ||
		check_line(squares[1], squares[4], squares[7]) ||
		check_line(squares[2], squares[5], squares[8]) ||
		check_line(squares[0], squares[4], squares[8]) ||
		check_line(squares[2], squares[4], squares[6])
		) {
		return true;
	}
	return false;

}

void Game::print_board() {
	int row = 1;
	for (auto object : squares) {
		if (object.getColor() == player1) {
			std::cout << "B ";
		}
		else if (object.getColor() == player2) {
			std::cout << "R ";
		}
		else {
			std::cout << "X ";
		}
		if (row % 3 == 0) {
			std::cout << std::endl;
		}
		row++;
	}
	std::cout << "-----" << std::endl;
}

void Game::undo_move() {
	if (!moves.empty()) {
		int move = moves.back();
		moves.pop_back();
		squares[move].changeColor(neutral);
		print_board();
		won = false;
		if (turn == player1) {
			turn = player2;
		}
		else {
			turn = player1;
		}
	}
}