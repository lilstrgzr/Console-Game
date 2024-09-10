#include "Creature.hpp"
#include "Toolbox.hpp"

Creature::Creature(){
    health_points = 1;
    damage_max = damage_min = 1;
    dodge_chance = 0;
    crit_chance = 0;
    icon = ' ';
}

unsigned Creature::hit(Creature& target) const {
    if (tb::chance(target.dodge_chance))
        return 0;
    unsigned damage = damage_min == damage_max ? damage_min : tb::rand(damage_min, damage_max + 1);
    if (damage == 0)
        return 0;
    if (tb::chance(crit_chance))
        damage *= 2;
    target.take_damage(damage);
    return damage;
}

void Creature::take_damage(unsigned damage){
    health_points -= damage > health_points ? health_points : damage;
}

unsigned Creature::getHP() const{
    return health_points;
}
