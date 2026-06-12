//
// Created by Admin on 03/11/2024.
//

#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include "Weapon.h"

#include <iostream>

#include "../GameManager.h"

Weapon::Weapon():Entity() {
    sprite.setPosition(100,100);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y);
    sprite.setScale(0.1f,0.1f);
}

Weapon::Weapon(const std::string &filename):Entity(filename,0) {

}

Weapon::Weapon(const std::string &filename, int munition, AmmoType ammoType):Entity(filename, 0) {
    this->ammoType = ammoType;
    this->totalAmmo = munition;
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    sprite.setScale(0.1f,0.1f);

}

Weapon::Weapon(const std::string &filename, int munition, AmmoType ammoType, float reloadTime, float shootTime,int magazineCapacity):Entity(filename,0){
    this->ammoType = ammoType;
    this->totalAmmo = munition;
    this->timeBetweenShoot  = shootTime;
    this->reloadTime = reloadTime;
    this->magazineCapacity = magazineCapacity;
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    sprite.setScale(0.1f,0.1f);
}


void Weapon::Update() {
    if (timeBeforeEndReloading > 0) {
        timeBeforeEndReloading -=  GameManager::GetInstance().deltaTime;
        if (timeBeforeEndReloading <= 0) {
            Reload();
        }
    }

    timeBeforeShoot -= timeBeforeShoot > 0 ? GameManager::GetInstance().deltaTime : 0;

}

void Weapon::Rotate() {
    sf::Vector2f currentPosition = sprite.getPosition();
    sf::Vector2i mousePos = sf::Mouse::getPosition(GameManager::GetInstance().window_);
    sf::Vector2f mousePosWorld = GameManager::GetInstance().window_.mapPixelToCoords(mousePos);

    float dirX = mousePosWorld.x - currentPosition.x;
    float dirY = mousePosWorld.y - currentPosition.y;

    angle = std::atan2(dirY, dirX);
    angle *= 180 /M_PI;
    sprite.setRotation(angle);
    ammunitionSpawnPosition.x = sprite.getPosition().x + cos(angle * M_PI/180) *(GetSpriteHalfWidth());
    ammunitionSpawnPosition.y = sprite.getPosition().y + sin(angle * M_PI/180) * (GetSpriteHalfWidth());
}

void Weapon::Shoot() {
    if (timeBeforeShoot<= 0 && !isReloading) {
        if(loadedAmmo > 0) {
            timeBeforeShoot = timeBetweenShoot;
            loadedAmmo--;
            GameManager::GetInstance().PlayerShoot(ammoType,ammunitionSpawnPosition);
        }
        else StartReload();
    }
}

void Weapon::StartReload() {
    if (!isReloading) {
        timeBeforeEndReloading = reloadTime;
        isReloading = true;
    }
}

void Weapon::Reload() {
    if (totalAmmo >= magazineCapacity) {
        loadedAmmo += magazineCapacity;
        totalAmmo -= magazineCapacity;
    }
    else {
        loadedAmmo += totalAmmo;
        totalAmmo = 0;
    }
    isReloading = false;
}

void Weapon::Display(sf::RenderWindow &window) {
    Entity::Display(window);
}


