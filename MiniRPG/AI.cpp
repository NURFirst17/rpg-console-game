#include "AI.h"
#include <cstdlib>

Action AI::chooseAction(int currentHP) {
    if (currentHP < 30) {
        int r = rand() % 3;
        if (r == 0) return Action::Heal;
        if (r == 1) return Action::Defend;
        return Action::Attack;
    }
    else {
        return (rand() % 2 == 0) ? Action::Attack : Action::Defend;
    }
}
