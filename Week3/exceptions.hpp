#pragma once

#include <iostream>

class unknown_color : public std::exception {
public:
	unknown_color(const std::string & name) :
		s{ std::string{ "unknown color [" } +name + "]" }
	{}
	unknown_color() :
		s("unknown color[]")
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class end_of_file : public std::exception {
};

class unknown_shape : public std::exception {
public:
	unknown_shape(const std::string & name) :
		s(std::string{ "unknown shape [" } +name + "]")
	{}

	unknown_shape() :
		s("unknown shape []")
	{}

	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class invalid_position : public std::exception {
public:
	invalid_position(const char & c) :
		s{ std::string{ "unknown position [" } +c + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};