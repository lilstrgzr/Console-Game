#pragma once
#include <string>
#include "Creature.hpp"

class Enemy : public Creature{
private:
	std::string name;
public:
	Enemy(char icon);

	Enemy(unsigned health_points, unsigned damage_min, unsigned damage_max, unsigned dodge_chance, unsigned crit_chanse, char icon, std::string name);

	void print_stats() const override;

	char getIcon() const;

	const std::string& getName() const;

	char setIcon();

};

