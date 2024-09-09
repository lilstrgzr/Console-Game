#include <iostream>
#include "Toolbox.hpp"
#include "Field.hpp"
#include"Player.hpp"
#include<Windows.h>

#define GAME_SPEED 500 //Задержка между шагами в мсек. чем меньше, тем быстрее

Field field(6, 5, 3, 3);
Player player;

int main() {
	player.startPlace(field);
	field.print_field();
	player.print_stats();

	try{
		while(true) {//TODO: Поменять условие
			player.move();
			Sleep(GAME_SPEED);
		}
	} 
	catch(const std::exception &ex){ 
		//TODO: 
	}



	tb::place_cursor(0, field.getHeight() + 3);

	return 0;
}