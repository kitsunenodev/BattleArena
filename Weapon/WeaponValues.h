//
// Created by f.collet on 25/11/2024.
//

#ifndef WEAPONVALUES_H
#define WEAPONVALUES_H

#include <map>
#include "../Ammo/Ammunition.h"

struct WeaponValue {
    int MagazineCapacity; // Number of ammunition in a magazine
    float ReloadTime; // Time required to reload the Weapon
    float FireRate; // Time between two shots fired
};

struct AmmunitionValue {
    int Damage;
    float speed;
};


class WeaponDataHolder{
public:
    inline const static std::map<AmmoType, WeaponValue> WeaponValues = {
            {REGULAR_AMMO,   {10,  1.f, 0.5f}},
            {EXPLOSIVE_AMMO, {1,   2.f, 1.f}},
            {FAST_AMMO,      {200, 1.f, 0.1f}}
    };
    inline const static std::map<AmmoType, AmmunitionValue> AmmunitionValues = {
            {REGULAR_AMMO, {5, 400.f}},
            {EXPLOSIVE_AMMO, {30, 150.f}},
            {FAST_AMMO, {2, 600.f}}
    };
};

#endif //WEAPONVALUES_H

