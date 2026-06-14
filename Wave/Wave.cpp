//
// Created by f.collet on 12/11/2024.
//

#include <functional>
#include "Wave.h"

void Wave::Update(float DeltaTime) {
    if (!waveStarted){
        TimerBeforeSpawn -= DeltaTime;
        if (TimerBeforeSpawn <= 0){
            StartWave();
        }
        return;
    }
    for (auto Spawner : SpawnerList){
        Spawner->Update(DeltaTime);
    }
}

bool Wave::isFinished() {
    if (!waveStarted) return false;
    for(auto spawner : SpawnerList){
        if (!spawner->SpawnerDepleted()) return false;
    }
    return true;
}

Wave::Wave(float timeBeforeSpawn, std::vector<Spawner*> enemySpawner):TimerBeforeSpawn(timeBeforeSpawn),SpawnerList(std::move(enemySpawner)) {}

void Wave::StartWave() {
    waveStarted = true;
}
