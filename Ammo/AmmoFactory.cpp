//
// Created by f.collet on 07/11/2024.
//

#include "AmmoFactory.h"

#include "ExplosiveAmmo.h"
#include "PenetrativeAmmo.h"
#include "RegularAmmo.h"
#include "../GameManager.h"
#include "../Entity/LivingEntity/Enemy/RegularEnemy.h"


Ammunition *AmmoFactory::CreateAmmo(AmmoType type, sf::Vector2f spawnPosition) {
    Ammunition* ammo = nullptr;
    switch (type) {
        case REGULAR_AMMO:
            ammo = new RegularAmmo(spawnPosition, GameManager::GetInstance().spriteManager.ammunitionSprites[0],250);
            break;
        case EXPLOSIVE_AMMO:
            ammo = new ExplosiveAmmo(spawnPosition, GameManager::GetInstance().spriteManager.ammunitionSprites[1],500);
            break;
        case FAST_AMMO:
            ammo = new PenetrativeAmmo(spawnPosition, GameManager::GetInstance().spriteManager.ammunitionSprites[2],150);
            break;
        default:
            ammo = new RegularAmmo(spawnPosition, GameManager::GetInstance().spriteManager.ammunitionSprites[0],250);
            break;
    }
    return ammo;
}
