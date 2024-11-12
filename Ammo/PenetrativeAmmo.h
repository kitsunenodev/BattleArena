//
// Created by f.collet on 07/11/2024.
//

#ifndef PENETRATIVEAMMO_H
#define PENETRATIVEAMMO_H
#include "Ammunition.h"


class PenetrativeAmmo : public Ammunition{
public:
    PenetrativeAmmo(sf::Vector2f spawnPosition,std::string& filename, int speed);
    void Update() override;
    void Rotate() override;

};



#endif //PENETRATIVEAMMO_H
