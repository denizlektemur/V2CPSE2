#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "player.hpp"
#include <array>

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
		std::function< bool() > condition,
		std::function< void() > work
	) : condition(condition),
		work(work)
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[key]()->bool { return sf::Keyboard::isKeyPressed(key); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[button]()->bool { return sf::Mouse::isButtonPressed(button); }
		),
		work(work)
	{}

	void operator()() {
		if (condition()) {
			work();
		}
	}
};

int main(int argc, char *argv[]) {
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	wall top{ "top", window, sf::Vector2f{ 30, 0}, sf::Vector2f{ 580, 30} };
	wall bottom{ "bottom", window, sf::Vector2f{ 30, 450}, sf::Vector2f{ 580, 30} };
	wall left{ "left", window, sf::Vector2f{ 0, 0 }, sf::Vector2f{ 30, 480 } };
	wall right{ "right", window, sf::Vector2f{ 610, 0 }, sf::Vector2f{ 30, 480} };
	ball my_ball{ "ball", window, sf::Vector2f{ 320.0, 240.0 } };
	player my_player{ "player", window, sf::Vector2f{ 400, 240 } };

	std::array< drawable *, 6 > objects = { &my_player, &top, &bottom, &left, &right, &my_ball};

	action actions[] = {
		action(sf::Keyboard::Left,  [&]() { my_player.move(sf::Vector2f(-1.0,  0.0)); }),
		action(sf::Keyboard::Right, [&]() { my_player.move(sf::Vector2f(+1.0,  0.0)); }),
		action(sf::Keyboard::Up,    [&]() { my_player.move(sf::Vector2f(0.0, -1.0)); }),
		action(sf::Keyboard::Down,  [&]() { my_player.move(sf::Vector2f(0.0, +1.0)); }),
		action(sf::Mouse::Left,     [&]() { my_player.jump(sf::Mouse::getPosition(window)); })
	};

	while (window.isOpen()) {
		for (auto & action : actions) {
			action();
		}

		window.clear();

		for (auto object : objects) {
			my_ball.checkCollision(object);
			object->update();
			object->draw();
		}


		window.display();

		sf::sleep(sf::milliseconds(20));

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}