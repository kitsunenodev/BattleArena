//
// Created by f.collet on 07/11/2024.
//

#include "Enemy.h"

Enemy::Enemy(const std::string &filename, int maxHealth, int armor, float speed, State* DefaultState)
        : LivingEntity(filename, maxHealth, armor, speed) {
    this->CurrentState = DefaultState;
    CurrentState->SetEnemy(this);
}

Enemy::Enemy(): LivingEntity() {
}

void Enemy::Update(){
    if(CurrentState == nullptr) return;
    CurrentState = CurrentState->StateUpdate();
}

void Enemy::Shoot() {

}
