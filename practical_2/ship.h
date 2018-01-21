//ship.h
#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"

class Ship : public sf::Sprite
{
protected:
  sf::IntRect _sprite;

  //default constructor is hidden
  Ship();
public:
  //constructor that takes a sprite
  explicit Ship(sf::IntRect ir);

  //pure virtual deconstructor -- makes this an abstract class
  virtual ~Ship() = 0;

  //update, virtual so can be overrided, but not pure virtual
  virtual void Update(const float &dt);
};


class Invader : public Ship
{
public:
  static bool direction;
  static float speed;
  Invader(sf::IntRect ir, sf::Vector2f pos);
  Invader();
  void Update(const float &dt) override;
};


void Invader::Update(const float &dt)
{
  //call base ship::update() to run generic ship logic
  Ship::Update(dt);
  //move left/right dictated by speed var
  move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

  //detect whether to drop or reverse
  if ((direction && getPosition().x > game_width - 16) ||
  (!direction && getPosition().x < 16))
  {
    direction = !direction;
    for (int i = 0; i < ships.size(); ++i)
    {
      ships[i]->move(0,24);
    }
  }
}
