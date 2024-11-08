//
// Created by Admin on 03/11/2024.
//

#include "Weapon.h"

Weapon::Weapon():Entity() {
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



