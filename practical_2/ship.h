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
  static bool direction; //can be accessed anywhere
  static float speed; // ""
  Invader(sf::IntRect ir, sf::Vector2f pos);
  Invader();
  void Update(const float &dt) override;
};


class Player : public Ship
{
public:
  //static bool p_direction;
  //static float p_speed;
  Player();
  void Update(const float &dt) override;
};
