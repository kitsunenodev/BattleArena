//
// Created by Admin on 03/11/2024.
//

#include "Weapon.h"

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

}

void Weapon::Shoot() {

}

void Weapon::Reload() {

}



