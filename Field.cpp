#include "Field.hpp"
#include "Toolbox.hpp"
#include <iostream>
#include<algorithm> // для std::fill

Field::Field(unsigned width, unsigned height, unsigned offsetWidth, unsigned offsetHeight){
	if (offsetWidth > 0)
		width += tb::rand(offsetWidth + 1);
	width = (width + 2) * 2 - 1;
	if (offsetHeight > 0)
		height += tb::rand(offsetHeight + 1);
	height += 2;

	start_x = tb::rand(4, width - 3);
	if (start_x % 2) --start_x;
	start_y = height - 2;

	data.resize(height);
	for (unsigned i = 0; i < height; ++i) {
		data[i].resize(width);
		std::fill(data[i].begin(), data[i].end(), ' '); //заполнение вектора какими-либо значениями
		for (unsigned j = 0; j < width; ++j) {
			if (j % 2) continue;
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				data[i][j] = '#';
			else if (i >= 2 && j >= 4 && i < height - 2 && j < width - 4)
				data[i][j] = '#';
		}
	}
}

void Field::print_field() const{
	for (unsigned i = 0; i < getHeight(); ++i) {
		for (unsigned j = 0; j < getWidth(); ++j) {
			std::cout << data[i][j];
		}
		std::cout << std::endl;
	}
	tb::place_text(start_x, start_y + 2, "^");
}

char Field::getCell(unsigned x, unsigned y) const { return data[y][x]; }

void Field::setCell(unsigned x, unsigned y, char icon){
	data[y][x] = icon;
}

size_t Field::getWidth() const{ return data[0].size(); }

size_t Field::getHeight() const{ return data.size();   }

unsigned Field::getStartX() const{ return start_x;     }

unsigned Field::getStartY() const { return start_y;    }
