//player.h
#pragma once
#include "entity.h"

class Player : public Entity
{
private:
  float _speed;

public:
  void update(double dt) override;
  Player();
  void render(sf::RenderWindow &window) const override;
};
