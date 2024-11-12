//
// Created by Admin on 03/11/2024.
//

#ifndef BATTLEARENA_AMMUNITION_H
#define BATTLEARENA_AMMUNITION_H
#include "../Entity//Entity.h"

enum AmmoType {
    REGULAR_AMMO,
    EXPLOSIVE_AMMO,
    PENETRATIVE_AMMO
};
class Ammunition : public Entity{
    Ammunition(sf::Vector2f spawnPosition);
protected:
    sf::Vector2f direction;
    void Update() override;


};




#endif //BATTLEARENA_AMMUNITION_H
