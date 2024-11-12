#include <iostream>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "GameManager.h"
#include "Entity/LivingEntity/Player.h"

int main()
{
  GameManager& gameManagerInstance = GameManager::GetInstance();
  const char *playerSprite = "../Sprites/raw/player/ship2.png";
  const char *BackgroundFile = "../Sprites/raw/grass_template2.jpg";
  Player player1  = Player(playerSprite,10,1,100);
  Background background = Background(BackgroundFile);
  gameManagerInstance.AddPlayer(&player1);
  gameManagerInstance.SetBackGround(background);
  sf::Clock clock;
  while (gameManagerInstance.window_.isOpen()) {
    sf::Event event;
    sf::Time time = clock.restart();
    gameManagerInstance.deltaTime  = time.asSeconds();

    while (gameManagerInstance.window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
          gameManagerInstance.window_.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::Escape)
            gameManagerInstance.window_.close();
      }
      if (event.type == sf::Event::MouseWheelScrolled){
        player1.SwitchWeapon(event.mouseWheelScroll.delta);


      }
    }
    gameManagerInstance.Update();


    gameManagerInstance.window_.clear();
    background.Display(gameManagerInstance.window_);
    gameManagerInstance.Display(gameManagerInstance.window_);
    gameManagerInstance.window_.display();

  }
}
