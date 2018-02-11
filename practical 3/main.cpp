//main.cpp
#include "player.h"
#include "entity.h"

using namespace sf;
using namespace std;

void Load()
{

}

void Update()
{

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
