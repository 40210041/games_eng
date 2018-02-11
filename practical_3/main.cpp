//main.cpp
#include "player.h"
#include "entity.h"

using namespace sf;
using namespace std;

void Load()
{

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
}

void Render(RenderWindow &window)
{

}

int main()
{
  RenderWindow window(VideoMode(600, 800), "TILE GAME");
  Load();
  while (window.isOpen())
  {
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }
  return 0;
}
