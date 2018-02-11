//entity.h
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Entity
{
protected:
  //smart pointers use reference counting to know where pointer is
  //stored. if it isnt stored anywhere then reference count = 0
  //and smart pointer deletes memory associated with it.
  //i.e u dont have to call delete() like u would w/ raw pointers
  std::unique_ptr<sf::Shape> _shape;
  sf::Vector2f _position;
  Entity(std::unique_ptr<sf::Shape> shp);

public:
  Entity() = delete;
  virtual ~Entity() = default;

  virtual void update(const double dt);
  virtual void render(sf::RenderWindow &window) const = 0;

  const sf::Vector2f getPosition();
  void setPosition(const sf::Vector2f &pos);
  void move(const sf::Vector2f &pos);
};
