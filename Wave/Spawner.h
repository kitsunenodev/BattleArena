//
// Created by Admin on 14/06/2026.
//

#ifndef BATTLEARENA_SPAWNER_H
#define BATTLEARENA_SPAWNER_H

#include <map>
#include "../Entity/LivingEntity/Enemy/Enemy.h"


class Spawner {
public:
    Spawner(sf::Vector2u position, int Range, std::vector<std::pair<EnemyType, float>> enemyList);
    void Update(float DeltaTime);
    bool SpawnerDepleted();

protected:
    int currentIndex = 0;
    float DeltaTimeSinceLastEnemyGeneration = 0.f;
    sf::Vector2i position = {0,0};
    int Range;
    std::vector<std::pair<EnemyType, float>> EnemyList;

    void SpawnNextEnemy();


};


#endif //BATTLEARENA_SPAWNER_H
