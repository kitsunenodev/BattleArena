//
// Created by f.collet on 07/11/2024.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Background.h"
#include "SpriteManager.h"
#include "WeaponValues.h"
#include "Ammo/Ammunition.h"
#include "Entity/LivingEntity/Enemy/Enemy.h"
#include "Entity/LivingEntity/Player.h"


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
        WeaponValues weaponValues;
        sf::RenderWindow window_;
        float deltaTime;
        ~GameManager() = default;
        static GameManager& GetInstance();
        void Update();
        void Display(sf::RenderWindow &window);
        void SetBackGround(Background& background);
        sf::Vector2u GetArenaSize();
        void PlayerShoot(AmmoType type,sf::Vector2f ammunitionSpawnPosition);
private:
        GameManager();

};



#endif //GAMEMANAGER_H
