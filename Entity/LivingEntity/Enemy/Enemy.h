//
// Created by f.collet on 07/11/2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../LivingEntity.h"
#include "States/State.h"
#include "../Player.h"

//Different types of enemy
enum EnemyType {
    REGULAR,
    ARMORED,
    FAST
};

//Base class for the enemy
class Enemy : public LivingEntity{
public:
    Enemy(const std::string &filename, int maxHealth, int armor, float speed, State* DefaultState);
    Enemy();
    void Update() override;
    void Shoot();

    //Distance at witch the player is detected by the enemy
    float DetectionRange = 100;

    //Distance at witch the enemy stop moving to start shooting at the player
    float ShootingRangeMin = 50;

    //Distance at witch the enemy start moving again to follow the player
    float ShootingRangeMax = 70;
    Player* CurrentTarget;

protected:
    State* CurrentState;

};



#endif //ENEMY_H
