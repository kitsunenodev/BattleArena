//
// Created by f.collet on 12/11/2024.
//

#ifndef QUICKENEMY_H
#define QUICKENEMY_H
#include "Enemy.h"


class FastEnemy: public Enemy{
public:
    FastEnemy(const std::string &filename, int maxHealth, int armor, float speed, State* DefaultState);
    void Update() override;
    void Rotate() override;
    void Display(sf::RenderWindow &window) override;

};



#endif //QUICKENEMY_H
