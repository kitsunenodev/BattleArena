//
// Created by f.collet on 12/11/2024.
//

#ifndef WAVE_H
#define WAVE_H
#include <vector>

#include "Entity/LivingEntity/Enemy/Enemy.h"


class Wave {
public:
    Wave(float timeBeforeSpawn, float timeBetweenSpawn, int nbEnemy);
    std::vector<EnemyType> enemies;

    void StartWave();
    void SpawnEnemy();
    bool isFinished();
protected:
    bool waveStarted = false;
    float timeBetweenEnemySpawn = 0;
    float timeBeforeEnemySpawn = 0;
    float currentTimer = 0;
    float currentEnemyIndex  = 0;


};



#endif //WAVE_H
