//
// Created by Admin on 03/11/2024.
//

#include "Ammunition.h"

#include <cmath>
#include <SFML/Window/Mouse.hpp>

#include "../GameManager.h"

Ammunition::Ammunition(sf::Vector2f spawnPosition, std::string& filename, int speed): Entity(filename,speed) {
    sprite.setPosition(spawnPosition.x,spawnPosition.y);
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f mousePosWorld = GameManager::GetInstance().window_.mapPixelToCoords(mousePosition);

    direction.x = mousePosWorld.x - spawnPosition.x;
    direction.y = mousePosWorld.y -  spawnPosition.y;

    angle = std::atan2(direction.y,direction.x);
    angle *= 180/M_PI;
    sprite.setRotation(angle);
}

void Ammunition::Update(){
    Move(direction.x, direction.y, GameManager::GetInstance().deltaTime);
}

Ammunition::~Ammunition() = default;



