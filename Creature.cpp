#include "Creature.hpp"

Creature::Creature(){
    health_points = 1;
    damage_max = damage_min = 1;
    dodge_chance = 0;
    crit_chance = 0;
}

unsigned Creature::hit(Creature& target) const {
    //TODO: проверка промоха и крит.удара

    return 0;
}

void Creature::take_damage(unsigned damage){
    health_points -= damage > health_points ? health_points : damage;
}
