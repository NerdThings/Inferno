#include "TestGame.h"

GAME_ENTRY
{
	TestGame* t = new TestGame();
	t->run();
	delete t;
	
	return 0;
}
