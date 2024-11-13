//
// Created by f.collet on 31/10/2024.
//

#include "Player.h"

#include <cmath>
#include <SFML/Window/Event.hpp>

#include "../../GameManager.h"
#include "../../Weapon/WeaponFactory.h"

Player::Player(const std::string &filename, int maxHealth, int armor, float speed): LivingEntity(filename,maxHealth,armor,speed) {
    verticalMovement = 0;
    horizontalMovement = 0;
    player_view.reset(sf::FloatRect(0.0f,0.0f,200.0f,200.0f));
    player_view.zoom(4.f);
    player_view.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));
    currentWeapon = nullptr;
    for (int i = 0; i < 3; ++i) {
        auto weapon = WeaponFactory::CreateWeapon(GameManager::GetInstance().spriteManager.weaponSprites[i],
            static_cast<AmmoType>(i),100, 1+i,0.1,10 );

        weapons_.push_back(weapon);

    }
    currentWeapon = weapons_[0];
}

void Player::Update() {
    if (currentWeapon == nullptr) {
        currentWeapon = *weapons_.begin();
    }
    timeLeftBeforeScroll -= GameManager::GetInstance().deltaTime;
    HandleInput(GameManager::GetInstance().deltaTime);
    Rotate();
    currentWeapon->Update();
    CalculateWeaponPosition();
    currentWeapon->SetPosition(weaponPosition.x, weaponPosition.y);

}

void Player::HandleInput(float deltaTime) {
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
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        currentWeapon->Shoot();
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(GameManager::GetInstance().window_);
        sf::Vector2f windowSize = GameManager::GetInstance().window_.getView().getSize();

        // Check if mouse is inside window
        if (mousePosition.x >= 0 && mousePosition.x < windowSize.x &&
            mousePosition.y >= 0 && mousePosition.y < windowSize.y) {
            currentWeapon->StartReload();
        }
    }


    Entity::Move(horizontalMovement, verticalMovement, deltaTime);

    ClampPosition();


    player_view.setCenter(sprite.getPosition());

}

void Player::Rotate() {
    sf::Vector2f currentPosition = sprite.getPosition();
    sf::Vector2i mousePos = sf::Mouse::getPosition(GameManager::GetInstance().window_);
    sf::Vector2f mousePosWorld = GameManager::GetInstance().window_.mapPixelToCoords(mousePos);

    float dirX = mousePosWorld.x - currentPosition.x;
    float dirY = mousePosWorld.y - currentPosition.y;

    angle = std::atan2(dirY, dirX);
    angle *= 180 /M_PI;
    sprite.setRotation(angle);

}

void Player::Display(sf::RenderWindow &window) {
    window.setView(player_view);
    Entity::Display(window);
    currentWeapon->Display(window);
}

void Player::ClampPosition() {
    float xMax = static_cast<float>(GameManager::GetInstance().GetArenaSize().x);
    float yMax = float(GameManager::GetInstance().GetArenaSize().y);


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

void Player::AddWeapon(Weapon* weapon) {
    weapons_.push_back(weapon);
}

void Player::CalculateWeaponPosition() {
    weaponPosition.x = sprite.getPosition().x + (cos(angle * M_PI/180) *
            (sprite.getTexture()->getSize().x/2 + currentWeapon->GetSprite().getOrigin().x/2));
    weaponPosition.y = sprite.getPosition().y+ (sin(angle *M_PI/180) * (sprite.getTexture()->getSize().y));
    currentWeapon->SetPosition(weaponPosition.x, weaponPosition.y);
    currentWeapon->Rotate();


}

void Player::SwitchWeapon(float scrollOffset){
    if (timeLeftBeforeScroll <= 0) {
        timeLeftBeforeScroll = scrollDelay;
        currentWeaponIndex += std::min(std::max(static_cast<int>(scrollOffset),-2),2);
        currentWeaponIndex = (weapons_.size() + currentWeaponIndex) % (weapons_.size()) ;
    }

    currentWeapon = weapons_[currentWeaponIndex];
}








