#include "TestGame.h"

class A {

};

class B : public A {

};

class C {

};

GAME_ENTRY
{
	TestGame* t = new TestGame();
	t->run();
	
	delete t;
	
	return 0;
}
