//
// Created by f.collet on 07/11/2024.
//

#include "AmmoFactory.h"

#include "ExplosiveAmmo.h"
#include "PenetrativeAmmo.h"
#include "RegularAmmo.h"


Ammunition *AmmoFactory::CreateAmmo(AmmoType type) {
    Ammunition* ammo;
    switch (type) {
        case REGULAR_AMMO:
            ammo = new RegularAmmo();
            break;
        case EXPLOSIVE_AMMO:
            ammo = new ExplosiveAmmo();
            break;
        case PENETRATIVE_AMMO:
            ammo = new PenetrativeAmmo();
            break;
        default:
            break;
    }
}
