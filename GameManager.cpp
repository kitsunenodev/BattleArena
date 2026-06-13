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
    std::vector<Entity*> EntityToDestroy;
    for (auto & player : players_) {
        player->Update();
    }
    for (auto & enemie : enemies_) {
        enemie->Update();
    }
    for (auto & playerProjectile : playerProjectiles) {
        if (playerProjectile == nullptr || playerProjectile->ShouldBeDestroyed){
            EntityToDestroy.push_back(playerProjectile);
            continue;
        }
        playerProjectile->Update();
    }
    for (auto & enemyProjectile : enemyProjectiles) {
        enemyProjectile->Update();
    }
    for (auto & entity : EntityToDestroy){
        std::remove(playerProjectiles.begin(), playerProjectiles.end(),entity);
        playerProjectiles.pop_back();
        delete entity;
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
    auto ammo  = AmmoFactory::CreateAmmo(type,ammunitionSpawnPosition);
    playerProjectiles.push_back(ammo);
}

float GameManager::GetDistanceFromClosestPlayer(sf::Vector2f position, Player* ClosestPlayer) {
    float distance = INFINITY;
    for (auto &player: players_){
        float distanceFromCurrentPlayer = static_cast<float>(sqrt(pow(position.x - player->GetSprite().getPosition().x, 2)
                                           + pow(position.y - player->GetSprite().getPosition().y, 2)));
        if (distanceFromCurrentPlayer < distance){
            distance = distanceFromCurrentPlayer;
            ClosestPlayer = player;
        }
    }
    return distance;
}

float GameManager::GetDistanceBetweenEntities(sf::Vector2f position1, sf::Vector2f position2) {
    return static_cast<float>(sqrt(pow(position2.x - position1.x, 2)
                            + pow(position1.y - position2.y, 2)));
}






