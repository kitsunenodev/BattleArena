//
// Created by f.collet on 12/11/2024.
//

#ifndef WAVE_H
#define WAVE_H
#include <vector>
#include "../Entity/LivingEntity/Enemy/Enemy.h"
#include "Spawner.h."


class Wave {
public:
    Wave(float timeBeforeSpawn, std::vector<Spawner*>enemySpawner);
    void StartWave();
    bool isFinished();
    void Update(float DeltaTime);

protected:
    bool waveStarted = false;
    float TimerBeforeSpawn;
    std::vector<Spawner*> SpawnerList;


};



#endif //WAVE_H
