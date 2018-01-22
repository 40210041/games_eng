//main.cpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ship.h"
#include "game.h"

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship *> ships;

void Load()
{
	//error message if file not found
  if (!spritesheet.loadFromFile("//Mac/Home/Desktop/games_eng/res/img/invaders_sheet.png"))
  {
    cerr << "Failed to load spritesheet!" << std::endl;
  }
  //set texture to invader sprite
  invader.setTexture(spritesheet);
  invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

  //vector of ships
  Player* player = new Player(sf::IntRect(0,0,32,32), {100,100});
  Invader* inv = new Invader(sf::IntRect(0,0,32,32), {100,100});
  ships.push_back(inv);

  for (int row = 0; row < invaders_rows; ++row)
  {
    auto rect = IntRect(0,0,32,32); //check the answer

    for (int column = 0; column < invaders_columns; ++column)
    {
		  Vector2f position = {100, 100}; //check the answer
      auto inv = new Invader(rect, position);
      ships.push_back(inv);
    }
  }
}

void Update(RenderWindow &window)
{
  // reset clock, recalculate deltatime
  static Clock clock;
  float dt = clock.restart().asSeconds();
  // check and consume events
  Event event;
  while (window.pollEvent(event))
  {
    if (event.type == Event::Closed)
    {
      window.close();
      return;
    }
  }
  // quit via esc key
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    window.close();
  }

  for (auto &s : ships)
  {
    s->Update(dt);
  }

  player.move(move_player * move_speed * dt, 0); //check for answer
}

void Render(RenderWindow &window)
{
  window.draw(invader);
  for (const auto s : ships)
  {
    window.draw(*s);
  }
}

int main()
{
  RenderWindow window(VideoMode(game_width, game_height), "SPACE INVADERS");
  Load();
  while(window.isOpen()){
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }
  return 0;
}
