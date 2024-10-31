//
// Created by f.collet on 31/10/2024.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class Entity {
protected:
    float speed;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    virtual ~Entity() = default;
    virtual void Update() = 0;
    Entity();
    Entity(const std::string &filename, float speed);
    void Move(int x, int y,float deltaTime);
    void Display(sf::RenderWindow &window);

};



#endif //ENTITY_H
