//
// Created by f.collet on 07/11/2024.
//

#include "Enemy.h"

Enemy::Enemy(const std::string &filename, int maxHealth, int armor, float speed)
        : LivingEntity(filename, maxHealth, armor, speed) {
}

Enemy::Enemy(): LivingEntity() {
}
