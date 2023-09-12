// main.cpp

#include "globals.h"
#include "Robot.h"
#include "Player.h"
#include "Arena.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Initialize the random number generator
  srand(static_cast<unsigned int>(time(0)));
    
    // Create a game
    // Use this instead to create a mini-game:   Game g(3, 3, 2)
  Game g(10, 15, 100);

    // Play the game
  g.play();
  return 0;
}
