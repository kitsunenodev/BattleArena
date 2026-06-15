//
// Created by Admin on 03/11/2024.
//

#ifndef BATTLEARENA_WEAPON_H
#define BATTLEARENA_WEAPON_H
#include "../Ammo/Ammunition.h"
#include "../Entity/Entity.h"


//Class that will handle the shooting logic for the player
class Weapon: public Entity {
protected:
    //The type of projectile this weapon will fire
    AmmoType ammoType;
    //time between two shot
    float timeBetweenShoot = 0;
    //time before the weapon can fire again
    float timeBeforeShoot = 0;
    float reloadTime = 0;
    float timeBeforeEndReloading = 0;
    bool isReloading = false;
    int totalAmmo = 0;
    //number of shot to fire before needing to reload
    int magazineCapacity = 0;

    //number of shot left before reloading
    int loadedAmmo = 0;
    sf::Vector2f ammunitionSpawnPosition;

public:
    Weapon();
    Weapon(const std::string& filename);
    Weapon(const std::string& filename, int munition, AmmoType ammoType);
    Weapon(const std::string& filename, int munition, AmmoType ammoType,
        float reloadTime, float shootTime, int magazineCapacity);
    void Update() override;
    void Rotate() override;
    void Shoot();
    void StartReload();
    void Reload();
    void Display(sf::RenderWindow& window) override;
};


#endif //BATTLEARENA_WEAPON_H
