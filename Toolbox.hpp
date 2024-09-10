#pragma once
#include <iostream>


namespace tb {
	unsigned rand(unsigned end);
	unsigned rand(unsigned begin, unsigned end);
	bool chance(unsigned percent);

	void place_cursor(unsigned x, unsigned y);

	template <typename ANY>
	void place_text(unsigned x, unsigned y, ANY text) {
		tb::place_cursor(x, y);
		std::cout << text;
	}

	void place_title(unsigned x, unsigned y, std::string text, unsigned widht, char space = ' ');

	void place_timer(unsigned x, unsigned y, unsigned delay, const char* text = "0");

}

