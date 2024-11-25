//
// Created by f.collet on 25/11/2024.
//

#ifndef WEAPONVALUES_H
#define WEAPONVALUES_H
#include "Ammo/Ammunition.h"

class WeaponValues {
public:
    std::vector<int> MagazinesCapacity = {
        10,
        1,
        200
    };
    std::vector<float> ReloadTimes = {
        1,
        2,
        1
    };

    std::vector<float>FireRates = {
        0.5,
        1,
        0.1
    };

};

#endif //WEAPONVALUES_H

