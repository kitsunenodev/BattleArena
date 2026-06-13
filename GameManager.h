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

struct WeaponValue {
    int MagazineCapacity; // Number of ammunition in a magazine
    float ReloadTime; // Time required to reload the Weapon
    float FireRate; // Time between two shots fired
};

struct AmmunitionValue {
    int Damage;
    float speed;
};


class GameManager {
protected:
        std::vector<Enemy*> enemies_;
        std::vector<Player*> players_;
        std::vector<Ammunition*> playerProjectiles;
        std::vector<Ammunition*> enemyProjectiles;
        Background background;

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
                {EXPLOSIVE_AMMO, {1,   2.f, 1.f}},
                {FAST_AMMO,      {200, 1.f, 0.1f}}
        };
        const std::map<AmmoType, AmmunitionValue> AmmunitionValues = {
            {REGULAR_AMMO, {5, 400.f}},
            {EXPLOSIVE_AMMO, {30, 150.f}},
            {FAST_AMMO, {2, 600.f}}
        };

        float GetDistanceFromClosestPlayer(sf::Vector2f position, Player* ClosestPlayer);

        float GetDistanceBetweenEntities(sf::Vector2f position1, sf::Vector2f position2);


private:
        GameManager();

};



#endif //GAMEMANAGER_H
