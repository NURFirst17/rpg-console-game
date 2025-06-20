#pragma once
#include "Player.h"
#include "Enemy.h"
#include "AI.h"

class Game {
private:
    Player player;
    Enemy enemy;

public:
    Game();
    void start();
    void showStatus();
};
