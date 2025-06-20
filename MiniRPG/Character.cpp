#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, int maxHp)
    : name(name), hp(maxHp), maxHp(maxHp), defending(false) {
}

int Character::getHP() const {
    return hp;
}

int Character::getMaxHP() const {
    return maxHp;
}

bool Character::isAlive() const {
    return hp > 0;
}

void Character::takeDamage(int amount) {
    if (defending)
        amount /= 2;

    hp -= amount;
    if (hp < 0) hp = 0;
}

void Character::heal() {
    int amount = 15;
    hp += amount;
    if (hp > maxHp) hp = maxHp;
}

void Character::defend() {
    defending = true;
}

void Character::resetDefense() {
    defending = false;
}

int Character::attack() const {
    return 10;
}

std::string Character::getName() const {
    return name;
}
