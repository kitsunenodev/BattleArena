//
// Created by f.collet on 07/11/2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../LivingEntity.h"
#include "States/State.h"
#include "../Player.h"

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
    void Shoot();

    float DetectionRange = 100;
    float ShootingRangeMin = 50;
    float ShootingRangeMax = 70;
    Player* CurrentTarget;

protected:
    State* CurrentState;

};



#endif //ENEMY_H
