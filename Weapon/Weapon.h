//
// Created by Admin on 03/11/2024.
//

#ifndef BATTLEARENA_WEAPON_H
#define BATTLEARENA_WEAPON_H
#include "../Ammo/Ammunition.h"
#include "../Entity/Entity.h"


class Weapon: public Entity {
protected:
    AmmoType ammoType;
    float timeBetweenShoot = 0;
    float timeBeforeShoot = 0;
    float reloadTime = 0;
    int TotalAmmo = 0;
    int loadedAmmo = 0;

public:
    Weapon();
    Weapon(const std::string& filename);
    Weapon(const std::string& filename, int munition, AmmoType ammoType);
    void Update() override;
    void Rotate() override;
    void Shoot();
    void Reload();


};


#endif //BATTLEARENA_WEAPON_H
