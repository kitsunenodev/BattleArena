//
// Created by f.collet on 07/11/2024.
//

#include "GameManager.h"

// GameManager &GameManager::getInstance() {
//     if (!instance) {
//         instance = new GameManager();
//     }
//     return *instance;
// }

GameManager::GameManager() {
    window_.create(sf::VideoMode(1920, 1080), "Main Scene", sf::Style::Fullscreen);
}

GameManager *GameManager::GetInstance(){
    if (!instance) {
        instance = new GameManager();
    }
    return instance;
}



void GameManager::Display(sf::RenderWindow &window) {
    for (Player* player : players_) {
        player->Display(window);
    }

    for (Enemy* enemy: enemies_) {
        enemy->Display(window);

    }

    for (Ammunition* ammo : playerProjectiles) {
        ammo->Display(window);
    }
    for (Ammunition* enemyAmmo : enemyProjectiles) {
        enemyAmmo->Display(window);
    }
}

void GameManager::SetBackGround(Background& background) {
    this->background = background;
}

sf::Vector2u GameManager::GetArenaSize() {
    return background.GetSize();
}


