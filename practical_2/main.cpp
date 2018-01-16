//main.cpp
//space invaders
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ship.h"

std::vector<Ship *>ships;

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

//load
void Load()
{
  // if (!spritesheet.loadFromFile("res/img/invaders_sheet.png"))
  // {
  //   cerr << "Failed to load spritesheet!" << std::endl;
  // }
  // invader.setTexture(spritesheet);
  // sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

//update
void Update()
{

}


//Render
void Render()
{
  // window.draw(invader);
}


//main
void main()
{

}
