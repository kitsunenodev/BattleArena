//
// Created by f.collet on 07/11/2024.
//

#include "GameManager.h"
#include <iostream>
#include "Ammo/AmmoFactory.h"
#include "Entity/LivingEntity/Enemy/EnemyFactory.h"


GameManager::GameManager(): deltaTime(0) {
    window_.create(sf::VideoMode(1920, 1080),"Main Scene", sf::Style::Fullscreen);
    spriteManager = SpriteManager();
}


GameManager &GameManager::GetInstance(){
    static GameManager instance;
    return instance;
}

//Handle the update off all of the entities as well as the wave progression
void GameManager::Update() {

    //List of the entities that will be destroyed at the end of the frame
    std::vector<Entity*> EntityToDestroy;

    //Check if the current wave is finished
    if (NbEnemySpawned == 0 && Waves[CurrentWaveIndex]->isFinished()){
        NextWave();
    }

    //Update the timer of the current wave
    Waves[CurrentWaveIndex]->Update(deltaTime);

    //Update the entities
    for(int i = 0; i < entities_.size(); ++i){
        if (entities_[i] == nullptr || entities_[i]->ShouldBeDestroyed){
            EntityToDestroy.push_back(entities_[i]);
            continue;
        }
        entities_[i]->Update();
    }

    //Handle the destruction of the entities
    for (auto & entity : EntityToDestroy){
        switch (entity->entityType) {
            case PLAYER:
                window_.close();
                return;
                break;
            case ENEMY:
                NbEnemySpawned--;
                break;

            default:
                break;
//            case PROJECTILE:
//                break;
//            case ENEMY_PROJECTILE:
//                break;
        }
        std::erase(entities_, entity);
        delete entity;
    }
}

//Handle the display of the entities
void GameManager::Display(sf::RenderWindow &window) {
    for (auto * entity : entities_){
        entity->Display(window);
    }
}

void GameManager::SetBackGround(Background& background) {
    this->background = background;
}

sf::Vector2u GameManager::GetArenaSize() {
    return background.GetSize();
}

void GameManager::AddPlayer(Player *player) {
    entities_.push_back(player);
}

void GameManager::PlayerShoot(AmmoType type,sf::Vector2f ammunitionSpawnPosition) {
    auto ammo  = AmmoFactory::CreateAmmo(type,ammunitionSpawnPosition);
    entities_.push_back(ammo);
}

float GameManager::GetDistanceFromClosestPlayer(sf::Vector2f position, Player*& ClosestPlayer) {
    float distance = INFINITY;
    for (auto &player: entities_){
        if(player->entityType != PLAYER) continue;
        const float distanceFromCurrentPlayer = static_cast<float>(pow(position.x - player->GetSprite().getPosition().x, 2)
                                           + pow(position.y - player->GetSprite().getPosition().y, 2));
        if (distanceFromCurrentPlayer < distance){
            distance = distanceFromCurrentPlayer;
            ClosestPlayer = dynamic_cast<Player*>(player);
        }
    }
    return sqrt(distance);
}

float GameManager::GetDistanceBetweenEntities(sf::Vector2f position1, sf::Vector2f position2) {
    return static_cast<float>(sqrt(pow(position2.x - position1.x, 2)
                            + pow(position1.y - position2.y, 2)));
}

void GameManager::GenerateEnemy(EnemyType type, sf::Vector2u vector2) {
    auto Enemy = EnemyFactory::CreateEnemy(type, vector2);
    entities_.push_back(Enemy);
    NbEnemySpawned++;

}

void GameManager::NextWave() {
    CurrentWaveIndex++;
    if (CurrentWaveIndex >= Waves.size()){
        window_.close();
    }
}

void GameManager::AddWaves(std::vector<Wave*>& WaveCollection) {
    Waves = WaveCollection;
}

void GameManager::GenerateWaves() {
    auto* CentralSpawner = new Spawner({GetArenaSize().x/2, GetArenaSize().y/2}, 100, DefaultSpawner);
    auto* CornerSpawner = new Spawner({GetArenaSize().x/2, 3 * GetArenaSize().y/4}, 100, DefaultSpawner);
    std::vector<Spawner*> spawnerList {CentralSpawner, CornerSpawner};
    Wave* wave1 = new Wave(10,spawnerList);
    Wave* wave2 = new Wave(10,spawnerList);
    std::vector<Wave*> waves {wave1, wave2};
    AddWaves(waves);
}






