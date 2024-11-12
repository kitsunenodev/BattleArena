//
// Created by f.collet on 31/10/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "LivingEntity.h"
#include "../../Weapon/Weapon.h"


class Player: public LivingEntity{
public:
    Player(const std::string &filename, int maxHealth, int armor, float speed);
    void Update() override;
    void Move(float deltaTime);
    void Rotate() override;
    void ClampPosition();
    void Display(sf::RenderWindow &window);
    void AddWeapon(Weapon* weapon);
    void SwitchWeapon(float scrollOffset);
protected:
    float scrollDelay = 0.1;
    float timeLeftBeforeScroll;
    sf::Vector2f weaponPosition;
    std::vector<Weapon*> weapons_;
    Weapon* currentWeapon{};
    int currentWeaponIndex{};
    sf::View player_view;
    int verticalMovement;
    int horizontalMovement;
    void CalculateWeaponPosition();


};



#endif //PLAYER_H
