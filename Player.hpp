#pragma once
#include "Creature.hpp"

class Player : public Creature{
private:
	unsigned x, y;
	unsigned direction; 
	unsigned max_hp;
	unsigned lvl;
	unsigned round;
public:
	Player();

	void print_stats() const override;

};

