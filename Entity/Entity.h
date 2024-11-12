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
    sf::Sprite sprite;
    sf::Texture texture;
    float angle = 0;
    float speed;

public:
    float GetSpriteHalfWidth() const;
    float GetSpriteHalfHeight() const;
    sf::Sprite GetSprite();
    void SetPosition(float x, float y);
    void ResetOrigin();
    virtual ~Entity() = default;
    virtual void Update() = 0;
    virtual void Rotate() = 0;
    Entity();
    Entity(const std::string &filename, float speed);
    void Move(int x, int y,float deltaTime);

    virtual void Display(sf::RenderWindow &window);

};



#endif //ENTITY_H
