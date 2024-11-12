//
// Created by f.collet on 12/11/2024.
//

#ifndef ARMOREDENEMY_H
#define ARMOREDENEMY_H
#include "Enemy.h"


class ArmoredEnemy : public Enemy{
public:
    ArmoredEnemy();
    void Update() override;
    void Rotate() override;

};



#endif //ARMOREDENEMY_H
