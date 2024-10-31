//
// Created by f.collet on 31/10/2024.
//

#include "Entity.h"

#include <cmath>
#include <SFML/Graphics/Texture.hpp>

Entity::Entity() {
    speed = 1;

}

Entity::Entity(const std::string &filename, float speed) {
    texture.loadFromFile(filename);
    this->sprite.setTexture(texture);
    this->speed = speed;
    sprite.setPosition(100,100);
}

void Entity::Move(int x, int y, float deltaTime) {
    float normalizedSpeedX = 0;
    float normalizedSpeedY = 0;
    float totalSpeedSquared = speed * speed;

    normalizedSpeedX = x * sqrt(totalSpeedSquared - (totalSpeedSquared * 0.5 * y));
    normalizedSpeedY = y * sqrt(totalSpeedSquared - (totalSpeedSquared * 0.5 * x));
    sprite.move(normalizedSpeedX * deltaTime, normalizedSpeedY * deltaTime);

}

void Entity::Display(sf::RenderWindow &window) {
    window.draw(sprite);
}



