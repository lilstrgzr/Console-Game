#pragma once
#include <string>

namespace up {
	const unsigned ups_number = 5;
	const std::string upgrades[]{
		"MAX HP" , "MIN DAMAGE" , "MAX DAMAGE", "DODGE CHANCE", "CRIT CHANCE"
	};
	const unsigned hp_up = 2;
	const unsigned auto_hp_up = 1;
	const unsigned dmg_up = 1;
	const unsigned dodge_up = 10;
	const unsigned crit_up = 5;
	const unsigned auto_crit_up = 1;
	const unsigned dodge_max = 90;
	const unsigned crit_max = 100;
}

