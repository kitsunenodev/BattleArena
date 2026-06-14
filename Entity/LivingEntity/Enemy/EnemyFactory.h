//
// Created by f.collet on 12/11/2024.
//

#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H
#include "Enemy.h"
#include "States/MovingState.h"
#include "States/IdleState.h"

class EnemyFactory {
public:
    static Enemy* CreateEnemy(EnemyType type, sf::Vector2u vector2U);

};



#endif //ENEMYFACTORY_H
