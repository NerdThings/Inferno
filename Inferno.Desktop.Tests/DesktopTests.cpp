#include <cstdio>
#include <cstdlib>

#include "TestGame.h"

int main()
{
	TestGame* t = new TestGame();
	t->run();
	
	delete t;
	
	return 0;
}
