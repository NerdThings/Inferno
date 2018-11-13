#include <cstdio>
#include <unistd.h>
#include <cstdlib>

#include "Game.h"

int main()
{
	//TestGame* t = new TestGame();
	//t->run();
	
	Inferno::Game* game = new Inferno::Game(360, 240);
	game->run();
	
	delete game;
	
	return 0;
}
