#pragma once
#include "Creature.hpp"
#include "Field.hpp"

//Директивы для интуитивности

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define START_PLAYER_HP 5


class Player : public Creature{
private:
	unsigned x, y;
	unsigned direction;  // 0 - up, 1 - right, 2 - down, 3 - left.
	unsigned max_hp;
	unsigned lvl;
	unsigned round;
	char getRandomEnemyType() const;
	void next_round();
	char next_cell() const;
public:
	Player();

	void print_stats() const override;

	void startPlace(Field& field);

	void move();

	void battle();
};

