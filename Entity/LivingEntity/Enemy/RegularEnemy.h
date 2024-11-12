//
// Created by f.collet on 07/11/2024.
//

#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "Enemy.h"


class RegularEnemy : public Enemy{
public:
    RegularEnemy();
    void Update() override;
    void Rotate() override;

};



#endif //BASICENEMY_H
