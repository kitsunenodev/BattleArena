//
// Created by f.collet on 07/11/2024.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <cmath>
#include "Background.h"
#include "SpriteManager.h"
#include "Weapon/WeaponValues.h"
#include "Ammo/Ammunition.h"
#include "Entity/LivingEntity/Enemy/Enemy.h"
#include "Entity/LivingEntity/Player.h"
#include "Wave/Wave.h"

struct WeaponValue {
    int MagazineCapacity; // Number of ammunition in a magazine
    float ReloadTime; // Time required to reload the Weapon
    float FireRate; // Time between two shots fired
};

struct AmmunitionValue {
    int Damage;
    float speed;
};

struct EnemyValue{
    int maxHealth;
    int armorPoint;
    float speed;
};


class GameManager {
protected:
        std::vector<Entity*> entities_;
//        std::vector<Enemy*> enemies_;
//        std::vector<Player*> players_;
//        std::vector<Ammunition*> playerProjectiles;
//        std::vector<Ammunition*> enemyProjectiles;
        std::vector<Wave*> Waves;
        Background background;
        void NextWave();
        int CurrentWaveIndex;
        int NbEnemySpawned;
        std::vector<std::pair<EnemyType, float>> DefaultSpawner = {
                {REGULAR, 0},
                {ARMORED, 10},
                {FAST, 5}
        };

public:
        void AddPlayer(Player* player);
        SpriteManager spriteManager;
        sf::RenderWindow window_;
        float deltaTime;
        ~GameManager() = default;
        static GameManager& GetInstance();
        void Update();
        void Display(sf::RenderWindow &window);
        void SetBackGround(Background& background);
        sf::Vector2u GetArenaSize();
        void PlayerShoot(AmmoType type,sf::Vector2f ammunitionSpawnPosition);
        const std::map<AmmoType, WeaponValue> WeaponValues = {
                {REGULAR_AMMO,   {10,  1.f, 0.5f}},
                {EXPLOSIVE_AMMO, {1, 2.f, 1.f}},
                {FAST_AMMO, {200, 1.f, 0.1f}}
        };
        const std::map<AmmoType, AmmunitionValue> AmmunitionValues = {
            {REGULAR_AMMO, {5, 400.f}},
            {EXPLOSIVE_AMMO, {30, 150.f}},
            {FAST_AMMO, {2, 600.f}}
        };

        const std::map<EnemyType, EnemyValue> EnemyValues = {
                {REGULAR, {20, 0, 90}},
                {ARMORED, {50, 10, 50}},
                {FAST, {10,0, 150}},
        };

        float GetDistanceFromClosestPlayer(sf::Vector2f position, Player*& ClosestPlayer);
        float GetDistanceBetweenEntities(sf::Vector2f position1, sf::Vector2f position2);
        void GenerateEnemy(EnemyType type, sf::Vector2<unsigned int> vector2);
        void AddWaves(std::vector<Wave*>& WaveCollection);
        void GenerateWaves();

private:
        GameManager();

};



#endif //GAMEMANAGER_H
