//
// Created by f.collet on 07/11/2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../LivingEntity.h"
#include "States/State.h"

enum EnemyType {
    REGULAR,
    ARMORED,
    FAST
};

class Enemy : public LivingEntity{
public:
    Enemy(const std::string &filename, int maxHealth, int armor, float speed, State* DefaultState);
    Enemy();
    void Update() override;

    float DetectionRange;
    float ShootingRangeMin;
    float ShootingRangeMax;

protected:
    State* CurrentState;
};



#endif //ENEMY_H
