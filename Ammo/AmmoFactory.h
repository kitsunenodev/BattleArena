//
// Created by f.collet on 07/11/2024.
//

#ifndef AMMOFACTORY_H
#define AMMOFACTORY_H
#include "Ammunition.h"


class AmmoFactory {
public:
    static Ammunition* CreateAmmo(AmmoType type, sf::Vector2f spawnPosition);

};



#endif //AMMOFACTORY_H
