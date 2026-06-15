//
// Created by Admin on 14/06/2026.
//

#include <iostream>
#include "Spawner.h"
#include "../GameManager.h"


Spawner::Spawner(sf::Vector2u position, int Range,std::vector<std::pair<EnemyType, float>> enemyList):
position(position), Range(Range), EnemyList(std::move(enemyList))
{
}

void Spawner::Update(float DeltaTime) {
    DeltaTimeSinceLastEnemyGeneration += DeltaTime;
    SpawnNextEnemy();
}

void Spawner::SpawnNextEnemy() {
    //if all enemies have been spawned we can return
    if (currentIndex >= EnemyList.size()) return;
    //if not enought time has passed since the creation of the last enemy we don't create the Enemy
    if (DeltaTimeSinceLastEnemyGeneration < EnemyList[currentIndex].second) return;

    //Create the enemy at a random location in the range of the spawner with a safety to prevent enemies spawning outside the map
    GameManager::GetInstance().GenerateEnemy(EnemyList[currentIndex].first, sf::Vector2u(
            std::max(static_cast<unsigned>(100),std::min(static_cast<unsigned int>(position.x + 2 *
            (static_cast<float>(rand())/ static_cast<float>(rand()) -0.5) * Range),
           GameManager::GetInstance().GetArenaSize().x - 100)),
            std::max(static_cast<unsigned>(100),std::min(static_cast<unsigned int>(position.y + 2 *
            (static_cast<float>(rand())/ static_cast<float>(rand()) -0.5) * Range),
           GameManager::GetInstance().GetArenaSize().y -100))
            ) );
    currentIndex++;
    DeltaTimeSinceLastEnemyGeneration = 0;
}

bool Spawner::SpawnerDepleted() {
    return currentIndex >= EnemyList.size();
}
