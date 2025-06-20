#pragma once
#include <string>

class Character {
protected:
    std::string name;
    int hp;
    int maxHp;
    bool defending;

public:
    Character(const std::string& name, int maxHp);
    virtual ~Character() {}

    int getHP() const;
    int getMaxHP() const;
    bool isAlive() const;
    void takeDamage(int amount);
    void heal();
    void defend();
    void resetDefense();
    int attack() const;

    std::string getName() const;
};
