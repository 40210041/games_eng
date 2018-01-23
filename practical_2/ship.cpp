//ship.cpp
#include "ship.h"
#include "game.h"
//#include "bullet.h"
using namespace sf;
using namespace std;

bool Invader::direction;
float Invader::speed;

const Keyboard::Key controls[3] = {
  Keyboard::Left, //left key
  Keyboard::Right, //right key
  Keyboard::Space, //shoot
};

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


// Player::Player() : Ship(IntRect(160,32,32,32))
// {
//   setPosition({game_height * .5f, game_height - 32.f});
// }
//
//
// // STILL NEED TO DO THIS!!! //
// void Player::Update(const float &dt)
// {
//   float move_player = 0.0f;
//   float move_speed = 400.f;
//
//   Ship::Update(dt);
//
//   if (Keyboard::isKeyPressed(controls[0])){   //move Left
//     move_player--;
//   }
//   if (Keyboard::isKeyPressed(controls[1])){   //move right
//     move_player++;
//   }
//   //move(move_player * move_speed * dt, 0);
//   player.move(move_player * move_speed * dt, 0); //check for answer

  // //its bullet time
  // static vector<Bullet* > bullets;
  // if (Keyboard::isKeyPressed(controls[3]))
  // {
  //   bullets.push_back(new Bullet(getPosition(), false));
  // }
  // for (const auto s : bullets)
  // {
  //   bullets.Update(dt);
  // }

// }
