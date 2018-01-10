//pong.cpp

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
  Keyboard::A, //p1 up
  Keyboard::Z, //p1 down
  Keyboard::Up, //p2 up
  Keyboard::Down //p2 down
};

//.f represents floating number e.g 3.0, 2.3, 4.5 etc...
const Vector2f paddleSize(25.f, 100.f); //Vector2f
const float ball_radius = 10.f; //ballRadius
const int game_width = 800; //gameWidth
const int game_height = 600; //gameHeight
const float paddle_speed = 400.f; //paddleSpeed

//create shapes
CircleShape ball;
RectangleShape paddles[2];

void Load(){
  //set size and origin of paddles
  for (auto &p : paddles){
    p.setSize(paddleSize - Vector2f(3, 3));
    p.setOrigin(paddleSize / 2.f);
  }

  //set size and origin of ball
  ball.setRadius(ball_radius - 3);
  ball.setOrigin(ball_radius / 2, ball_radius / 2);

  //reset paddle position
  paddles[0].setPosition(10 + paddleSize.x / 2, game_height / 2);
  paddles[1].setPosition();

  //reset ball position
  ball.setPosition();
}
