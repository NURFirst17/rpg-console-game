#pragma once

enum class Action {
    Attack,
    Defend,
    Heal
};

class AI {
public:
    static Action chooseAction(int currentHP);
};
