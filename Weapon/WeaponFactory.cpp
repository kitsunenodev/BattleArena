//
// Created by f.collet on 08/11/2024.
//

#include "WeaponFactory.h"

Weapon *WeaponFactory::CreateWeapon(const std::string &filename, const AmmoType ammoType, const int nbMunition, float reloadTime, float shootTime,int magazineCapacity) {
    return new Weapon(filename, nbMunition, ammoType, reloadTime, shootTime, magazineCapacity);
}
