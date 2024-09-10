#include "Enemy.hpp"
#include "Toolbox.hpp"
#include "Field.hpp"

extern Field field;

Enemy::Enemy(char icon, unsigned lvl){
	this->icon = icon;
	switch (icon) {
	case 'X':
		health_points = 2 + lvl;
		damage_min = 1;
		damage_max = 1 + lvl / 2;
		dodge_chance = 10;
		name = "Robber";
		break;
	case 'P':
		health_points = 3 + lvl;
		damage_min = 1 + lvl/3;
		damage_max = 1 + lvl /3;
		name = "Butcher";
		break;
	case 'S':
		health_points = 2 + lvl;
		damage_min = 1;
		damage_max = 1 + lvl / 4;
		dodge_chance = 5 + lvl * 2;
		name = "Snake";
		break;
	case 'T':
		health_points = 3 + lvl * 2;
		damage_min = 0;
		damage_max = 1 + lvl / 3;
		name = "Thug";
		break;
	default: 
		throw std::exception("invalid enemy type");
	}
}

Enemy::Enemy(unsigned health_points, unsigned damage_min, unsigned damage_max, unsigned dodge_chance, unsigned crit_chanse, char icon, std::string name){
	this->health_points = health_points;
	this->damage_min = damage_min;
	this->damage_max = damage_max;
	this->dodge_chance = dodge_chance;
	this->crit_chance = crit_chanse;
	this->icon = icon;
	this->name = name;
}

void Enemy::print_stats() const{
	unsigned x = field.getWidth() + 5;
	tb::place_title(x, 9, name + "STATS ", 16, '-');
	tb::place_text(x, 10, std::string("Health points: ") + std::to_string(health_points));
	tb::place_text(x, 11, std::string("Damage: ") + (damage_min == damage_max ? std::to_string(damage_min) : (std::to_string(damage_min) + '-' + std::to_string(damage_max))));
	tb::place_text(x, 12, std::string("Dodge chance: ") + std::to_string(dodge_chance));
}

char Enemy::getIcon() const{
	return icon;
}

const std::string& Enemy::getName() const{
	return name;
}

char Enemy::setIcon(){
	return 0;
}
