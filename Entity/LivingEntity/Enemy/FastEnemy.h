//
// Created by f.collet on 12/11/2024.
//

#ifndef QUICKENEMY_H
#define QUICKENEMY_H
#include "Enemy.h"


class FastEnemy: public Enemy{
public:
    FastEnemy();
    void Update() override;
    void Rotate() override;

};



#endif //QUICKENEMY_H
