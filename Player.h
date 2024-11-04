//
// Created by f.collet on 31/10/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "LivingEntity.h"


class Player: public LivingEntity{
public:
    Player(const std::string &filename, int maxHealth, int armor, float speed);
    void Update() override;
    void Move(float deltaTime);
    void Rotate(sf::RenderWindow & window) override;
    void ClampPosition();
protected:
    int verticalMovement;
    int horizontalMovement;

};



#endif //PLAYER_H
