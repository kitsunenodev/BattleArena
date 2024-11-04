#include <iostream>
#include <SFML/Graphics.hpp>

#include "Background.h"
#include "Player.h"

int main()
{

  const char *playerSprite = "../Sprites/raw/player/ship2.png";
  const char *BackgroundFile = "../Sprites/raw/grass_template2.jpg";
  Player player1  = Player(playerSprite,10,1,100);
  Background background = Background(BackgroundFile);
  sf::RenderWindow window(sf::VideoMode(900,600),"Main Scene");
  sf::Clock clock;
  while (window.isOpen()) {
    sf::Event event;
    sf::Time time = clock.restart();
    float deltaTime = time.asSeconds();

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    player1.Rotate(window);
    player1.Move(deltaTime);
    window.clear();
    background.Display(window);
    player1.Display(window);
    window.display();
  }
}
