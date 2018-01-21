//ship.cpp
#include "ship.h"
#include "game.h"
using namespace sf;
using namespace std;

bool Invader::direction;
float Invader::speed;

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


Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16,16);
  setPosition(pos);
}

void Invader::Update(const float &dt)
{
  Ship::Update(dt);
}
