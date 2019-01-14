#include "SFML/Graphics.hpp"
#include "rectangle.hpp"
#include <vector>
#include <iostream>
#include "game.hpp"

int main() {
	sf::RenderWindow window{ sf::VideoMode{640, 640}, "Tic-Tac-Toe" };
	Game tic_tac_toe(window);

	while (window.isOpen()) {
		window.clear();
		tic_tac_toe.draw_board();
		window.display();
		
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			}
			tic_tac_toe.undo_move();
		}
		while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			}
			sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(window));
			tic_tac_toe.make_move(position);
		}

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		sf::sleep(sf::milliseconds(20));
	}
	return 0;
}