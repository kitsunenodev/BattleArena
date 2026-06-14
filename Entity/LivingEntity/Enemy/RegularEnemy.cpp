//
// Created by f.collet on 07/11/2024.
//

#include "RegularEnemy.h"

RegularEnemy::RegularEnemy(const std::string &filename, int maxHealth, int armor, float speed, State *DefaultState)
        : Enemy(filename, maxHealth, armor, speed, DefaultState) {

}

void RegularEnemy::Update() {
    Enemy::Update();
}

void RegularEnemy::Rotate() {

}

void RegularEnemy::Display(sf::RenderWindow &window) {
    Entity::Display(window);
}
