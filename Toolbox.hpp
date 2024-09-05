#pragma once



namespace tb {
	unsigned rand(unsigned end);
	unsigned rand(unsigned begin, unsigned end);
	bool chance(unsigned percent);

	void place_cursor(unsigned x, unsigned y);

	void place_text(unsigned x, unsigned y, const char* text);

	void place_timer(unsigned x, unsigned y, unsigned delay, const char* text = "0");
}

