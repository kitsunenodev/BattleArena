//
// Created by f.collet on 12/11/2024.
//

#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H
#include <vector>

class SpriteManager {
public:
    const char* playerSprite = "Sprites/raw/player/ship2.png";
    std::vector<const char*> ammunitionSprites  = {
        "../Sprites/raw/projectiles/shotsmall.png",
        "../Sprites/raw/projectiles/shotbig.png",
        "../Sprites/raw/projectiles/shotoval.png"
    };
    std::vector<const char*> enemySprites ={
        "../Sprites/raw/enemies/rocketship/png",
        "../Sprites/raw/enemies/rocketship/png",
        "../Sprites/raw/enemies/rocketship/png"
    };
    std::vector<const char*> weaponSprites = {
        "../Sprites/ArmoredSoldier/weapon_1.png",
        "../Sprites/ArmoredSoldier/weapon_2.png",
        "../Sprites/ArmoredSoldier/weapon_3.png"
    };
};
#endif //SPRITEMANAGER_H
