//
// Created by Admin on 03/11/2024.
//

#ifndef BATTLEARENA_AMMUNITION_H
#define BATTLEARENA_AMMUNITION_H
#include "../Entity//Entity.h"

enum AmmoType {
    REGULAR_AMMO,
    EXPLOSIVE_AMMO,
    FAST_AMMO
};
class Ammunition : public Entity{
public:
    Ammunition(sf::Vector2f spawnPosition, std::string& filename, float speed, int AmmunitionDamage);
    ~Ammunition();

    int Damage;
    void Update() override;
protected:
    sf::Vector2f direction;

};

#endif //BATTLEARENA_AMMUNITION_H
