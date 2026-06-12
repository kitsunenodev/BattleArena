//
// Created by f.collet on 07/11/2024.
//

#include "ExplosiveAmmo.h"

ExplosiveAmmo::ExplosiveAmmo(sf::Vector2f spawnPosition, std::string& filename, float speed, int AmmoDamage):
Ammunition(spawnPosition,filename,speed, AmmoDamage) {

}

void ExplosiveAmmo::Rotate() {

}

void ExplosiveAmmo::Update() {
 Ammunition::Update();
}


