//main.cpp
//space invaders
#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"

std::vector<Ship *>ships;

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

//load
void Load()
{
  if (!spritesheet.loadFromFile("res/img/invaders_sheet.png"))
  {
    cerr << "Failed to load spritesheet!" << std::endl;
  }
  invader.setTexture(spritesheet);
  sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

//update
void Update(RenderWindow &window)
{
  //reset clock, recalculate deltatime (dt)
  static Clock clock;
  float dt =  clock.restart().asSeconds();
  //check and consume events
  Event event;
  while (window.pollEvent(event))
  {
    if (event.type == Event::Closed)
    {
      window.close();
      return;
    }
  }

  //quit via escape Key
  if (Keyboard::isKeyPressed(Keyboard::Escape))
  {
    window.close();
  }
}


//Render
void Render(RenderWindow &window)
{
  window.draw(invader);
}


//main
void main()
{
  RenderWindow window(VideoMode(game_width, game_height), "SPACE INVADER");
  Load();
  while (window.isOpen()){
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }
}
