//
// Created by f.collet on 07/11/2024.
//

#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "Enemy.h"


class BasicEnemy : public Enemy{
    void Update() override;
    void Rotate(sf::RenderWindow &window) override;

};



#endif //BASICENEMY_H
