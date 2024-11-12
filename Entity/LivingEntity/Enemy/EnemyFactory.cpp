//
// Created by f.collet on 12/11/2024.
//

#include "EnemyFactory.h"

#include "ArmoredEnemy.h"
#include "FastEnemy.h"
#include "RegularEnemy.h"

Enemy *EnemyFactory::CreateEnemy(EnemyType type) {
    Enemy* enemy;
    switch (type) {
        case REGULAR:
            enemy = new RegularEnemy();
            break;

        case FAST:
            enemy = new FastEnemy();
            break;

        case ARMORED:
            enemy = new ArmoredEnemy();
            break;


        default:
            enemy = new RegularEnemy();
            break;
    }
    return enemy;
}

