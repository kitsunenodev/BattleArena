#include <iostream>
#include <SFML/Graphics.hpp>

#include "Background.h"
#include "GameManager.h"
#include "Entity/Player.h"

GameManager* GameManager::instance = nullptr;
int main()
{

  GameManager* instance = GameManager::GetInstance();
  const char *playerSprite = "../Sprites/raw/player/ship2.png";
  const char *BackgroundFile = "../Sprites/raw/grass_template2.jpg";
  const char *WeaponSprite = "../Sprites/raw/projectiles/rocket.png";
  Weapon weapon =  Weapon(WeaponSprite);
  Player player1  = Player(playerSprite,10,1,100);
  player1.AddWeapon(&weapon);
  Background background = Background(BackgroundFile);
  instance->SetBackGround(background);
  sf::Clock clock;
  while (GameManager::GetInstance()->window_.isOpen()) {
    sf::Event event;
    sf::Time time = clock.restart();
    float deltaTime = time.asSeconds();

    while (GameManager::GetInstance()->window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        GameManager::GetInstance()->window_.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::Escape)
        GameManager::GetInstance()->window_.close();
      }
    }
    player1.Update();
    player1.Rotate();
    player1.Move(deltaTime);
    GameManager::GetInstance()->window_.clear();
    background.Display(GameManager::GetInstance()->window_);
    player1.Display(GameManager::GetInstance()->window_);
    GameManager::GetInstance()->window_.display();

  }
}
