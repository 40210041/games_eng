//player.cpp
#include "player.h"
using namespace sf;
using namespace std;

const Keyboard::Key controls[4] =
{
  Keyboard::Up,
  Keyboard::Down,
  Keyboard::Left,
  Keyboard::Right
};

void Player::update(double dt)
{
  //move in for directions based on keys

  Entity::update(dt);
}

Player::Player() : _speed(200.f), Entity(make_unique<CircleShape>(25.f))
{
  _shape->setFillColor(Color::Magenta);
  _shape->setOrigin(Vector2f(25.f,25.f));
}

void Player::render(sf::RenderWindow &window) const
{
  window.draw(*_shape);
}
