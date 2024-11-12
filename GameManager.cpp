//
// Created by f.collet on 07/11/2024.
//

#include "GameManager.h"

#include <iostream>

#include "Ammo/AmmoFactory.h"


GameManager::GameManager(): deltaTime(0) {
    window_.create(sf::VideoMode(1920, 1080),"Main Scene", sf::Style::Fullscreen);
    spriteManager = SpriteManager();
}

GameManager &GameManager::GetInstance(){
    static GameManager instance;
    return instance;

}

void GameManager::Update() {
    for (auto & player : players_) {
        player->Update();

    }
    for (auto & enemie : enemies_) {
        enemie->Update();
    }
    for (auto & playerProjectile : playerProjectiles) {
        playerProjectile->Update();
    }
    for (auto & enemyProjectile : enemyProjectiles) {
        enemyProjectile->Update();
    }
}

void GameManager::Display(sf::RenderWindow &window) {
    for (Player* player : players_) {
        player->Display(window);
    }

    for (Enemy* enemy: enemies_) {
        enemy->Display(window);
    }

    for (Ammunition* ammo : playerProjectiles) {
        std::cout << "ammo1"<< std::endl;
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

void GameManager::AddPlayer(Player *player) {
    players_.push_back(player);
}

void GameManager::PlayerShoot(AmmoType type,sf::Vector2f ammunitionSpawnPosition) {
    std::cout << "shoot game manager"<< std::endl;
    auto ammo  = AmmoFactory::CreateAmmo(type,ammunitionSpawnPosition);
    playerProjectiles.push_back(ammo);
    std::cout << playerProjectiles[0]<< std::endl;
}





