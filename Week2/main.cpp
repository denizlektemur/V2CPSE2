#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "Player.hpp"
#include "Wall.hpp"

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
	wall left_wall{ sf::Vector2f{ 30.0, 30.0 }, { sf::Vector2f{ 30, 420 } } };
	wall right_wall{ sf::Vector2f{ 580.0, 30.0 }, { sf::Vector2f{ 30, 420 } } };
	wall top_wall{ sf::Vector2f{ 30.0, 30.0 }, { sf::Vector2f{ 580, 30 } } };
	wall bottom_wall{ sf::Vector2f{ 30.0, 420.0 }, { sf::Vector2f{ 580, 30 } } };

	ball my_ball{ sf::Vector2f{ 100.0, 100.0 } };
	player my_player{ sf::Vector2f{ 320.0, 240.0} };
	
	action actions[] = {
		action(sf::Keyboard::Left,  [&]() { my_player.move(sf::Vector2f(-1.0,  0.0)); }),
		action(sf::Keyboard::Right, [&]() { my_player.move(sf::Vector2f(+1.0,  0.0)); }),
		action(sf::Keyboard::Up,    [&]() { my_player.move(sf::Vector2f(0.0, -1.0)); }),
		action(sf::Keyboard::Down,  [&]() { my_player.move(sf::Vector2f(0.0, +1.0)); }),
		action(sf::Mouse::Left,     [&]() { my_player.jump(sf::Mouse::getPosition(window)); })
	};

	float ballHorizontalSpeed = 4;
	float ballVerticalSpeed = 4;

	while (window.isOpen()) {
		for (auto & action : actions) {
			action();
		}

		my_ball.setX(my_ball.getX() + ballHorizontalSpeed);
		my_ball.setY(my_ball.getY() + ballVerticalSpeed);

		if (my_ball.getHitbox().intersects(top_wall.getHitbox())) {
			my_ball.setY(61);
			ballVerticalSpeed *= -1;
		}
		else if (my_ball.getHitbox().intersects(bottom_wall.getHitbox())) {
			my_ball.setY(359);
			ballVerticalSpeed *= -1;
		}
		else if (my_ball.getHitbox().intersects(left_wall.getHitbox())) {
			my_ball.setX(61);
			ballHorizontalSpeed *= -1;
		}
		else if (my_ball.getHitbox().intersects(right_wall.getHitbox())) {
			my_ball.setX(519);
			ballHorizontalSpeed *= -1;
		}

		if (my_player.getTopHitbox().intersects(my_ball.getHitbox())) {
			my_ball.setY(my_player.getTop() - 61);
			ballVerticalSpeed *= -1;
		}
		else if (my_player.getBottomHitbox().intersects(my_ball.getHitbox())) {
			my_ball.setY(my_player.getBottom() + 1);
			ballVerticalSpeed *= -1;
		}
		else if (my_player.getLeftHitbox().intersects(my_ball.getHitbox())) {
			std::cout << ballHorizontalSpeed << "  " << ballVerticalSpeed << "\n";
			std::cout << "hit";
			my_ball.setX(my_player.getLeft() - 61);
			ballHorizontalSpeed *= -1;
			std::cout << ballHorizontalSpeed << "  " << ballVerticalSpeed << "\n";
		}
		else if (my_player.getRightHitbox().intersects(my_ball.getHitbox())) {
			my_ball.setX(my_player.getRight() + 1);
			ballHorizontalSpeed *= -1;
		}

		window.clear();

		my_ball.draw(window);
		my_player.draw(window);
		left_wall.draw(window);
		right_wall.draw(window);
		top_wall.draw(window);
		bottom_wall.draw(window);

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