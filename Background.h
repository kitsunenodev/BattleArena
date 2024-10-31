//
// Created by f.collet on 31/10/2024.
//

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class Background {
protected:
    sf::Texture texture_;
    sf::Sprite sprite_;
public:
    Background(const std::string &filename);
    void Display(sf::RenderWindow &window);
};



#endif //BACKGROUND_H
