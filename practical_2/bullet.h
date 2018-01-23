//bullet.h
//only need one bullet class as the 2 types are so similar
#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite
{
public:
  void Update(const float &dt);
  Bullet(const sf::Vector2f &pos, const bool mode);
  ~Bullet()=default;

protected:
  Bullet();
  //false = player bullet, true = enemy bullet
  bool _mode;
};
