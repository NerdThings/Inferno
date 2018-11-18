#include "TestGame.h"

//GAME_ENTRY
int main()
{
	TestGame* t = new TestGame();
	t->run();
	
	delete t;
	
	return 0;
}
