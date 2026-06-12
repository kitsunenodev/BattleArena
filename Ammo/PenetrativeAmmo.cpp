//
// Created by f.collet on 07/11/2024.
//

#include "PenetrativeAmmo.h"

PenetrativeAmmo::PenetrativeAmmo(sf::Vector2f spawnPosition, std::string& filename, float speed, int AmmoDamage):
Ammunition(spawnPosition, filename, speed, AmmoDamage) {}

void PenetrativeAmmo::Rotate() {

}

void PenetrativeAmmo::Update() {
    Ammunition::Update();
}



