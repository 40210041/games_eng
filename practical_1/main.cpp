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
Vector2f ball_velocity; //ballVelocity
bool server = false;
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

  //set velocity
  ball_velocity = {server ? 100.0f : -100.0f, 60.0f};
  //set size and origin of ball
  ball.setRadius(ball_radius - 3);
  ball.setOrigin(ball_radius / 2, ball_radius / 2);
  //reset paddle position
  paddles[0].setPosition(10 + paddleSize.x / 2, game_height / 2);
  paddles[1].setPosition(10 + paddleSize.x /2, game_height / 2);
  //reset ball position
  ball.setPosition();

  //load font face from res dir
  font.loadFromFile("res/fonts/Arcade.ttf");
  //set text element to use font
  text.setFont(font);
  //set character size to 24 pixels
  text.setCharatcterSize(24);
}

void reset(){
  //update score text
  text.setString();
  //keep score text centered
  text.setPosition((game_width * 0.5f) - (text.getLocalBounds().width) * 0.5f, 0);
}

void Update(RenderWindow &window){
  //reset clock, recalculate deltatime
  static Clock clock;
  float dt = clock.restart().asSeconds();
  ball.move(ball_velocity * dt);
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
  float direction = 0.0f;
  if (Keyboard::isKeyPressed(controls[0])){
    direction--;
  }
  if (Keyboard::isKeyPressed(controls[1])){
    direction++;
  }
  paddles[0].move(0, direction * paddle_speed * dt);

  //check ball collision
  const float bx = ball.getPosition().x;
  const float by = ball.getPosition().y;
  if (by > game_height){
    //bottom wall
    ball_velocity.x *= 1.1f;
    ball_velocity.y *= -1.1f;
    ball.move(0, -10);
  }
  else if (by < 0){
    ball_velocity.x *= 1.1f;
    ball_velocity.y *= -1.1f;
    ball.move(0, 10);
  }
  else if (bx > game_width){
    //right wall
    reset();
  }
  else if (bx < 0){
    //left wall
    reset();
  }
  else if (
    //ball is inline or behind paddle
    bx < paddleSize.x &&
    //AND ball is belpw top edge of paddle
    by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
    //AND ball is above bottom edge of paddle
    by < paddles[0].getPosition().y + (paddleSize * 0.5)
  ) {
    //bounce off left paddle
  }
  else if (...){
    //bounce off right paddle
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
  Load();
  while (window.isOpen()){
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }
  return 0;
}
