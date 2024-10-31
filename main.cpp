#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"

int main()
{

  const char *playerSprite = "../Sprites/raw/player/ship2.png";
  Player player1  = Player(playerSprite,10,1,100);
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

    player1.Move(deltaTime);
    window.clear();
    player1.Display(window);
    window.display();
  }
}
