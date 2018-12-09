#include "drawable.hpp"
#include "ball.hpp"
#include "picture.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "operators.hpp"
#include "exceptions.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

drawable * drawable_read(std::ifstream & input) {
	sf::Vector2f position;
	std::string name;
	input >> position >> name;

	if (name == "CIRCLE") {
		sf::Color color;
		float size;
		input >> color >> size;

		return new ball(position, size, color);

	}
	else if (name == "RECTANGLE") {
		sf::Color color;
		sf::Vector2f size;
		input >> color >> size;
		return new rectangle(position, size, color);

	}
	else if (name == "PICTURE") {
		sf::Vector2f size;
		std::string path;
		input >> path;
		input >> size;
		return new picture(position, size, path);
	}
	else if (name == "") {
		throw end_of_file();
	}

	throw unknown_shape(name);
}

int main(int argc, char *argv[]) {
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "Factory" };

	std::vector<drawable *> screen_objects;

	std::ifstream objects_file("objects.txt");
	try {
		for (;;) {
			screen_objects.push_back(drawable_read(objects_file));
		}
		objects_file.close();
	}
	catch (end_of_file) {
		objects_file.close();
	}
	catch (std::exception & problem) {
		std::cout << problem.what();
		objects_file.close();
		return 0;
	}

	window.clear();
	for (auto const & object : screen_objects) {
		object->draw(window);
	}
	window.display();

	while (window.isOpen()) {


		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {

				std::ofstream buffer_file("ObjectsBuffer.txt");
				for (auto const & object : screen_objects) {
					buffer_file << (object->get_position());
					if (dynamic_cast<ball*>(object)) {
						buffer_file << " CIRCLE ";
						buffer_file << (object->get_color());
						buffer_file << (object->get_size().x);
					}
					else if (dynamic_cast<rectangle*>(object)) {
						buffer_file << " RECTANGLE ";
						buffer_file << (object->get_color());
						buffer_file << (object->get_size());
					}
					else if (dynamic_cast<picture*>(object)) {
						buffer_file << " PICTURE ";
						buffer_file << (object->get_path()) << " ";
						buffer_file << (object->get_size());
					}
					else {
						throw unknown_shape();
					}
					buffer_file << "\n";

				}

				buffer_file.close();
				std::string lines;
				std::ifstream buffered_file("ObjectsBuffer.txt");
				std::ofstream objects_file("objects.txt");
				while (getline(buffered_file, lines)) {
					objects_file << lines << "\n";
				}
				buffered_file.close();
				objects_file << lines;
				objects_file.close();
				window.close();
			}

			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				for (auto object : screen_objects) {
					sf::Vector2f new_position;
					if (object->get_hitbox().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
							new_position = sf::Vector2f(sf::Mouse::getPosition(window));
							object->set_position(new_position);
							window.clear();
							for (auto const object : screen_objects) {
								object->draw(window);
							}
							window.display();
						}
					}
				}
			}
		}
		sf::sleep(sf::milliseconds(20));
	}
	return 0;
}