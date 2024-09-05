#pragma once
#include <vector>


class Field{
private:
	std::vector<std::vector<char>> data;
	unsigned start_x;
	unsigned start_y;
public:
	Field(unsigned width, unsigned height, unsigned offsetWidth = 3, unsigned offsetHeight = 3);
	
	void print_field() const;


	size_t getWidth() const;
	size_t getHeight() const;
};

