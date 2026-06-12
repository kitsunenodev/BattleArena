//
// Created by f.collet on 07/11/2024.
//

#include "RegularAmmo.h"

RegularAmmo::RegularAmmo(sf::Vector2f spawnPosition, std::string& filename, float speed, int AmmoDamage): Ammunition(spawnPosition, filename, speed, AmmoDamage) {

}

void RegularAmmo::Rotate() {

}

void RegularAmmo::Update() {
    Ammunition::Update();
}

