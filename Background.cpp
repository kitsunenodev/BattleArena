//
// Created by f.collet on 31/10/2024.
//

#include "Background.h"

Background::Background(const std::string &filename) {
    texture_.loadFromFile(filename);
    sprite_.setTexture(texture_);
}
Background::Background() {
}

void Background::Display(sf::RenderWindow& window) {
    window.draw(sprite_);
}

sf::Vector2u Background::GetSize() {
    return texture_.getSize();
}



