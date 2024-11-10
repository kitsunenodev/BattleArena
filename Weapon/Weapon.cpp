//
// Created by Admin on 03/11/2024.
//

#include <SFML/Window/Mouse.hpp>
#include <valarray>
#include "Weapon.h"
#include "../GameManager.h"

Weapon::Weapon():Entity() {
    sprite.setPosition(100,100);
}

Weapon::Weapon(const std::string &filename):Entity(filename,0) {

}

Weapon::Weapon(const std::string &filename, int munition, AmmoType ammoType):Entity(filename, 0) {
    this->ammoType = ammoType;
    this->TotalAmmo = munition;

}




void Weapon::Update() {

}

void Weapon::Rotate() {
    sf::Vector2f currentPosition = sprite.getPosition();
    sf::Vector2i mousePos = sf::Mouse::getPosition(GameManager::GetInstance()->window_);
    sf::Vector2f mousePosWorld = GameManager::GetInstance()->window_.mapPixelToCoords(mousePos);

    float dirX = mousePosWorld.x - currentPosition.x;
    float dirY = mousePosWorld.y - currentPosition.y;

    angle = std::atan2(dirY, dirX);
    angle *= 180 /M_PI;
    sprite.setRotation(angle);


}

void Weapon::Shoot() {

}

void Weapon::Reload() {

}



