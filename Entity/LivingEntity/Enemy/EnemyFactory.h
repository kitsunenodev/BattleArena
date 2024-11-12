//
// Created by f.collet on 12/11/2024.
//

#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H
#include "Enemy.h"


class EnemyFactory {
public:
    static Enemy* CreateEnemy(EnemyType type, sf::Vector2f spawnPosition);

};



#endif //ENEMYFACTORY_H
