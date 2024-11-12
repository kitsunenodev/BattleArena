//
// Created by f.collet on 08/11/2024.
//

#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H
#include "Weapon.h"


class WeaponFactory {
public:
    static Weapon* CreateWeapon(const std::string& filename, AmmoType ammoType, int nbMunition);




};



#endif //WEAPONFACTORY_H
