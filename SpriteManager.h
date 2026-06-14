//
// Created by f.collet on 12/11/2024.
//

#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H
#include <vector>

class SpriteManager {
public:
    const char* playerSprite = "Sprites/raw/player/ship2.png";
    std::vector<std::string> ammunitionSprites  = {
        "../Sprites/raw/projectiles/shotsmall.png",
        "../Sprites/raw/projectiles/rocket.png",
        "../Sprites/raw/projectiles/shotwave.png"
    };
    std::vector<std::string> enemySprites ={
        "../Sprites/raw/enemies/core.png",
        "../Sprites/raw/enemies/rocketship.png",
        "../Sprites/raw/enemies/shieldship.png"
    };
    std::vector<std::string> weaponSprites = {
        "../Sprites/ArmoredSoldier/weapon_1.png",
        "../Sprites/ArmoredSoldier/weapon_3.png",
        "../Sprites/ArmoredSoldier/weapon_2.png"
    };
};
#endif //SPRITEMANAGER_H
