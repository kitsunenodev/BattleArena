//
// Created by f.collet on 07/11/2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../LivingEntity.h"


class Enemy : public LivingEntity{
public:
    Enemy(const std::string &filename, int maxHealth, int armor, float speed);

};



#endif //ENEMY_H
