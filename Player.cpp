//
// Created by f.collet on 31/10/2024.
//

#include "Player.h"

#include <SFML/Window/Event.hpp>
Player::Player(const std::string &filename, int maxHealth, int armor, float speed): LivingEntity(filename,maxHealth,armor,speed) {
    verticalMovement = 0;
    horizontalMovement = 0;

}

void Player::Update() {

}

void Player::Move(float deltaTime) {
    horizontalMovement = 0;
    verticalMovement = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        verticalMovement -=1;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        horizontalMovement -=1;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        verticalMovement +=1;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        horizontalMovement +=1;
    }

    Entity::Move(horizontalMovement, verticalMovement, deltaTime);




}

