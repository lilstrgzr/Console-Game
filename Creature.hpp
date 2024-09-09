#pragma once


class Creature{
protected:
	unsigned health_points;
	unsigned damage_min;
	unsigned damage_max;
	unsigned dodge_chance;
	unsigned crit_chance;
	char icon;
public:
	Creature();

	virtual unsigned hit(Creature& target)const ;
	virtual void take_damage(unsigned damage);
	virtual void print_stats() const = 0;

};

