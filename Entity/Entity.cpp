//
// Created by f.collet on 31/10/2024.
//

#include "Entity.h"
#include <cmath>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

Entity::Entity() {
    speed = 0;
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);

}

Entity::Entity(const std::string &filename, float speed) {
    texture.loadFromFile(filename);
    this->sprite.setTexture(texture);
    this->speed = speed;
    sprite.setPosition(100,100);
    ResetOrigin();
}

void Entity::Move(int x, int y, float deltaTime) {
    float normalizedSpeedX = 0;
    float normalizedSpeedY = 0;
    float totalSpeedSquared = speed * speed;

    normalizedSpeedX = x * sqrt(totalSpeedSquared - (totalSpeedSquared * 0.5 * abs(y)));
    normalizedSpeedY = y * sqrt(totalSpeedSquared - (totalSpeedSquared * 0.5 * abs(x)));
    sprite.move(normalizedSpeedX * deltaTime, normalizedSpeedY * deltaTime);

}

float Entity::GetSpriteHalfWidth() const {
    return texture.getSize().x/2;
}

float Entity::GetSpriteHalfHeight() const {
    return texture.getSize().y/2;
}

void Entity::Display(sf::RenderWindow &window) {
    window.draw(sprite);
}
void Entity::ResetOrigin() {
    sprite.setOrigin(GetSpriteHalfWidth(),GetSpriteHalfHeight());
}

sf::Sprite Entity::GetSprite() {
    return sprite;
}

void Entity::SetPosition(float x, float y) {
    sprite.setPosition(x,y);
}

void Entity::RotateGlobal(sf::Vector2f position, float angle) {
    sprite.setRotation(angle);
}




