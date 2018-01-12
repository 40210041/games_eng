//pong.cpp
//coords are reversed, up = --, down = ++, left = --, right = ++
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
const int game_width = 800; //gameWidth y
const int game_height = 600; //gameHeight x
const float paddle_speed = 600.f; //paddleSpeed
//create shapes
CircleShape ball;
RectangleShape paddles[2]; //0 is left, 1 is right

Vector2f ball_velocity; //ballVelocity
bool server = false;

int score_0 = 0;
int score_1 = 0;

void reset(){
  score_0 ++;
  score_1 ++;
  //reset paddle position
  paddles[0].setPosition(10 + paddleSize.x / 2, game_height / 2);
  paddles[1].setPosition(760 + paddleSize.x / 2, game_height / 2);
  //reset ball position
  ball.setPosition(game_width / 2, game_height / 2);

  // //update score text
  // text.setString("Hello :D");
  // //keep score text centered
  // text.setPosition((game_width * 0.5f) - (text.getLocalBounds().width) * 0.5f, 0);
}

void Load(){
  //set size and origin of paddles
  for (auto &p : paddles){
    p.setSize(paddleSize - Vector2f(3, 3));
    p.setOrigin(paddleSize / 2.f);
  }
  //set size and origin of ball
  ball.setRadius(ball_radius - 3);
  ball.setOrigin(ball_radius / 2, ball_radius / 2);
  //set velocity
  ball_velocity = {server ? 100.0f : -100.0f, 60.0f};

  // //load font face from res dir
  // font.loadFromFile("res/fonts/Arcade.ttf");
  // //set text element to use font
  // text.setFont(font);
  // //set character size to 24 pixels
  // text.setCharatcterSize(24);
}

void Update(RenderWindow &window){
  //reset clock, recalculate deltatime
  static Clock clock;
  float dt = clock.restart().asSeconds();
  ball.move(ball_velocity * dt);

  const float pad_0 = paddles[0].getPosition().y;
  const float pad_1 = paddles[1].getPosition().y;

  //check and consume events
  Event event;
  while (window.pollEvent(event)){
    if (event.type == Event::Closed){
      window.close();
      return;
    }
  }
  //quit via esc key
  if (Keyboard::isKeyPressed(Keyboard::Escape)){
    window.close();
  }

  //handle paddle movement
  //left paddle
  float direction = 0.0f;
  float direction_2 = 0.0f;

  // if (Keyboard::isKeyPressed(controls[0])){
  //   direction--;
  // }
  // if (Keyboard::isKeyPressed(controls[1])){
  //   direction++;
  // }

  if (paddles[0].getPosition().y > ball.getPosition().y){
    direction --;
  }
  if (paddles[0].getPosition().y < ball.getPosition().y){
    direction ++;
  }

  paddles[0].move(0, direction * paddle_speed * dt);
  if (pad_0 + (paddleSize.y * 0.5) >= game_height){
    paddles[0].move(0,-10);
  }
  if (pad_0 - (paddleSize.y * 0.5) <= 0){
    paddles[0].move(0,10);
  }

  //right paddle
  if (Keyboard::isKeyPressed(controls[2])){
    direction_2--;
  }
  if (Keyboard::isKeyPressed(controls[3])){
    direction_2++;
  }
  paddles[1].move(0, direction * paddle_speed * dt);
  if (pad_1 + (paddleSize.y * 0.5) >= game_height){
    paddles[1].move(0,-10);
  }
  if (pad_1 - (paddleSize.y * 0.5) <= 0){
    paddles[1].move(0,10);
  }

  //check ball collision
  const float ball_x = ball.getPosition().x; //bx
  const float ball_y = ball.getPosition().y; //by

  if (ball_y > game_height){
    //bottom wall
    ball_velocity.x *= 1.1f;
    ball_velocity.y *= -1.1f;
    ball.move(0, -10);
  }
  else if (ball_y < 0){
    ball_velocity.x *= 1.1f;
    ball_velocity.y *= -1.1f;
    ball.move(0, 10);
  }
  else if (ball_x > game_width){
    //right wall
    reset();
  }
  else if (ball_x < 0){
    //left wall
    reset();
  }
  else if (
    //ball is inline or behind paddle
    ball_x < paddleSize.x &&
    //AND ball is below top edge of paddle
    ball_y > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
    //AND ball is above bottom edge of paddle
    ball_y < paddles[0].getPosition().y + (paddleSize.y * 0.5)
  ){
    //bounce off left paddle
    ball_velocity.x *= -1.1f;
    ball_velocity.y *= 1.1f;
    ball.move(0,0);
  }
  else if( //right paddle
    ball_x > game_width - paddleSize.x &&
    ball_y > paddles[1].getPosition().y - (paddleSize.y * 0.5) &&
    ball_y < paddles[1].getPosition().y + (paddleSize.y * 0.5)
  ){
    //bounce off right paddle
    ball_velocity.x *= -1.1f;
    ball_velocity.y *= 1.1f;
    ball.move(0,0);
  }
}

void Render(RenderWindow &window){
  //draw everything
  window.draw(paddles[0]);
  window.draw(paddles[1]);
  window.draw(ball);
}

int main(){
  RenderWindow window(VideoMode(game_width, game_height), "PONG");
  reset();
  Load();
  while (window.isOpen()){
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }
  return 0;
}
