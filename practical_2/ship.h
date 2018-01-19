//ship.h
#pragma once
#include <SFML/Graphics.hpp>

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
