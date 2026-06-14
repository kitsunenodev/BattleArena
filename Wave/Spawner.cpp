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
    if (currentIndex >= EnemyList.size()) return;
    if (DeltaTimeSinceLastEnemyGeneration < EnemyList[currentIndex].second) return;
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
