#include <iostream>
#include <SFML/Graphics.hpp>

#include "Background.h"
#include "GameManager.h"
#include "Entity/Player.h"

int main()
{

  GameManager& instance = GameManager::GetInstance();
  const char *playerSprite = "../Sprites/raw/player/ship2.png";
  const char *BackgroundFile = "../Sprites/raw/grass_template2.jpg";
  const char *WeaponSprite = "../Sprites/raw/projectiles/rocket.png";
  Weapon weapon =  Weapon(WeaponSprite);
  Player player1  = Player(playerSprite,10,1,100);
  player1.AddWeapon(&weapon);
  Background background = Background(BackgroundFile);
  instance.SetBackGround(background);
  sf::Clock clock;
  while (instance.window_.isOpen()) {
    sf::Event event;
    sf::Time time = clock.restart();
    float deltaTime = time.asSeconds();

    while (instance.window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
          instance.window_.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::Escape)
            instance.window_.close();
      }
    }
    player1.Update();
    player1.Rotate();
    player1.Move(deltaTime);

    instance.window_.clear();
    background.Display(instance.window_);
    player1.Display(instance.window_);
      instance.window_.display();

  }
}
