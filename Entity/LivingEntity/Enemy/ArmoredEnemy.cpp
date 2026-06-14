//
// Created by f.collet on 12/11/2024.
//

#include "ArmoredEnemy.h"

ArmoredEnemy::ArmoredEnemy(const std::string &filename, int maxHealth, int armor, float speed, State *DefaultState)
        : Enemy(filename, maxHealth, armor, speed, DefaultState) {

}

void ArmoredEnemy::Update() {
    Enemy::Update();
}

void ArmoredEnemy::Rotate() {

}

void ArmoredEnemy::Display(sf::RenderWindow &window) {
    Entity::Display(window);
}
