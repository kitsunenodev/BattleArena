//
// Created by f.collet on 12/11/2024.
//

#include "FastEnemy.h"


FastEnemy::FastEnemy(const std::string &filename, int maxHealth, int armor, float speed, State *DefaultState) : Enemy(
        filename, maxHealth, armor, speed, DefaultState) {}

void FastEnemy::Update() {
    Enemy::Update();
}

void FastEnemy::Rotate() {

}

void FastEnemy::Display(sf::RenderWindow &window) {
    Entity::Display(window);
}
