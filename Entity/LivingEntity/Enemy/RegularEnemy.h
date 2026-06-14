//
// Created by f.collet on 07/11/2024.
//

#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "Enemy.h"


class RegularEnemy : public Enemy{
public:
    RegularEnemy(const std::string &filename, int maxHealth, int armor, float speed, State* DefaultState);
    void Update() override;
    void Rotate() override;
    void Display(sf::RenderWindow &window) override;

};



#endif //BASICENEMY_H
