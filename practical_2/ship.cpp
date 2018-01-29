//ship.cpp

#include "ship.h"
#include "game.h" //for spritesheet

using namespace sf;
using namespace std;
bool Invader::direction = 20;
float Invader::speed = 20;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite()
{
  _sprite = ir;
  setTexture(spritesheet);
  setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

//define the ship deconstructor
//although we set this to pure virtual, we still have to define it
Ship::~Ship() = default;

//3.5
Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void Invader::Update(const float &dt)
{
  //call base ship::update to run generic ship logic
  Ship::Update(dt);

  //3.5.1
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
