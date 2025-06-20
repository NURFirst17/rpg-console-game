#include "Game.h"
#include <iostream>

Game::Game() : player("Player"), enemy("AI") {}

void Game::showStatus() {
    std::cout << "+------------------------------+\n";
    std::cout << "|     Battle: Player vs AI     |\n";
    std::cout << "+------------------------------+\n";
    std::cout << "| Player: HP " << player.getHP() << "/" << player.getMaxHP() << "\n";
    std::cout << "| AI:     HP " << enemy.getHP() << "/" << enemy.getMaxHP() << "\n";
    std::cout << "+------------------------------+\n";
}

void Game::start() {
    while (player.isAlive() && enemy.isAlive()) {
        player.resetDefense();
        enemy.resetDefense();

        showStatus();
        std::cout << "| >> Choose your action:\n";
        std::cout << "| [1] Attack   [2] Defend\n";
        std::cout << "| [3] Heal\n";
        std::cout << "+------------------------------+\n";
        std::cout << "| [Enter] Confirm move\n";
        std::cout << "+------------------------------+\n";

        int choice;
        std::cin >> choice;

        // AI action
        Action aiAction = AI::chooseAction(enemy.getHP());

        // Player action
        switch (choice) {
        case 1:
            enemy.takeDamage(player.attack());
            std::cout << "* You attacked the AI.\n";
            break;
        case 2:
            player.defend();
            std::cout << "* You chose to defend.\n";
            break;
        case 3:
            player.heal();
            std::cout << "* You healed yourself.\n";
            break;
        default:
            std::cout << "* Invalid choice.\n";
            continue;
        }

        // AI action
        switch (aiAction) {
        case Action::Attack:
            player.takeDamage(enemy.attack());
            std::cout << "* AI attacks you.\n";
            break;
        case Action::Defend:
            enemy.defend();
            std::cout << "* AI defends.\n";
            break;
        case Action::Heal:
            enemy.takeDamage(-15); // heal
            std::cout << "* AI heals itself.\n";
            break;
        }

        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
        system("cls"); // clear screen
    }

    if (player.isAlive())
        std::cout << "You win!\n";
    else
        std::cout << "AI wins!\n";
}
