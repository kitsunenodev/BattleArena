//
// Created by Admin on 14/06/2026.
//

#ifndef BATTLEARENA_SPAWNER_H
#define BATTLEARENA_SPAWNER_H

#include <map>
#include "../Entity/LivingEntity/Enemy/Enemy.h"

//Class that handle the spawn of some enemies
class Spawner {
public:
    Spawner(sf::Vector2u position, int Range, std::vector<std::pair<EnemyType, float>> enemyList);
    void Update(float DeltaTime);

    // Function to know if all the enemies of this spawner have been spawned
    bool SpawnerDepleted();

protected:

    //keep track of the next Enemy to spawn
    int currentIndex = 0;
    float DeltaTimeSinceLastEnemyGeneration = 0.f;

    //The Base position of the spawner
    sf::Vector2i position = {0,0};

    //Range around the spawner where the enemy can randomly spawn
    int Range;

    //List of the Enemies to spawn. The float value indicate the time required since the creation of the previous
    //before creating this enemy
    std::vector<std::pair<EnemyType, float>> EnemyList;

    void SpawnNextEnemy();


};


#endif //BATTLEARENA_SPAWNER_H
