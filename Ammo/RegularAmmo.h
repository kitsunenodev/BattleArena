//
// Created by f.collet on 07/11/2024.
//

#ifndef REGULARAMMO_H
#define REGULARAMMO_H
#include "Ammunition.h"


class RegularAmmo: public Ammunition{
public:
    RegularAmmo(sf::Vector2f spawnPosition, std::string& filename, int speed);
    void Update() override;
    void Rotate() override;

};



#endif //REGULARAMMO_H
