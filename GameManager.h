//
// Created by f.collet on 07/11/2024.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <list>

#include "Background.h"
#include "Ammo/Ammunition.h"
#include "Entity/Enemy.h"
#include "Entity/Player.h"


class GameManager {
protected:
        std::list<Enemy*> enemies_;
        std::list<Player*> players_;
        std::list<Ammunition*> playerProjectiles;
        std::list<Ammunition*> enemyProjectiles;
        Background background;

public:
        static GameManager& GetInstance();
        sf::RenderWindow window_;
        void Display(sf::RenderWindow &window);
        void SetBackGround(Background& background);
        sf::Vector2u GetArenaSize();
        ~GameManager() = default;
private:
        GameManager();

};



#endif //GAMEMANAGER_H
