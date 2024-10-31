//
// Created by f.collet on 31/10/2024.
//

#include "Background.h"

Background::Background(const std::string &filename) {
    texture_.loadFromFile(filename);
    sprite_.setTexture(texture_);
}

void Background::Display(sf::RenderWindow& window) {
    window.draw(sprite_);
}


