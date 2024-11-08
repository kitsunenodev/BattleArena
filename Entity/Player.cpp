//
// Created by f.collet on 31/10/2024.
//

#include "Player.h"

#include <cmath>
#include <iostream>
#include <SFML/Window/Event.hpp>

#include "../GameManager.h"

Player::Player(const std::string &filename, int maxHealth, int armor, float speed): LivingEntity(filename,maxHealth,armor,speed) {
    verticalMovement = 0;
    horizontalMovement = 0;
    player_view.reset(sf::FloatRect(0.0f,0.0f,200.0f,200.0f));
    player_view.zoom(4.f);
    player_view.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));


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
    currentWeapon->GetSprite().setPosition(
        sprite.getPosition().x + GetSpriteHalfWidth()+ currentWeapon->GetSpriteHalfWidth(),
        sprite.getPosition().y);
    ClampPosition();
    player_view.setCenter(sprite.getPosition());

}

void Player::Rotate() {
    sf::Vector2f currentPosition = sprite.getPosition();
    sf::Vector2i mousePos = sf::Mouse::getPosition(GameManager::GetInstance()->window_);
    sf::Vector2f mousePosWorld = GameManager::GetInstance()->window_.mapPixelToCoords(mousePos);

    float dirX = mousePosWorld.x - currentPosition.x;
    float dirY = mousePosWorld.y - currentPosition.y;

    float angle = std::atan2(dirY, dirX);
    angle *= 180 /M_PI;
    sprite.setRotation(angle);
    currentWeapon->GetSprite().setOrigin(sprite.getPosition() - currentWeapon->GetSprite().getPosition());
    currentWeapon->GetSprite().setRotation(angle);
    currentWeapon->ResetOrigin();

}

void Player::Display(sf::RenderWindow &window) {
    window.setView(player_view);
    Entity::Display(window);
    //currentWeapon->Display(window);
}

void Player::ClampPosition() {
    float xMax = static_cast<float>(GameManager::GetInstance()->GetArenaSize().x);
    float yMax = float(GameManager::GetInstance()->GetArenaSize().y);


    float posX = std::max(
        std::min(sprite.getPosition().x ,
            xMax -GetSpriteHalfWidth()),
        0.f + GetSpriteHalfWidth());

    float posY = std::max(
        std::min(sprite.getPosition().y ,
            yMax -sprite.getTexture()->getSize().y/2),
            0.f + sprite.getTexture()->getSize().y/2);
    sprite.setPosition(posX,posY);



}







