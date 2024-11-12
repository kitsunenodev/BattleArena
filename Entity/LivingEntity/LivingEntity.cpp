//
// Created by f.collet on 31/10/2024.
//

#include "LivingEntity.h"

LivingEntity::LivingEntity(const std::string &filename, int maxHealth, int armor, float speed):Entity(filename,speed){
    this->armorPoint = armor;
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
}

LivingEntity::LivingEntity(): maxHealth(0), currentHealth(0), armorPoint(0) {
}
