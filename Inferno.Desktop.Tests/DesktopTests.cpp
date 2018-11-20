#include "TestGame.h"

class A {

};

class B : public A {

};

class C {

};

GAME_ENTRY
{
	A a;
	B b;
	C c;
	
	
	bool test = std::is_base_of<typeof(a), typeof(b)>();
	
	TestGame* t = new TestGame();
	t->run();
	
	delete t;
	
	return 0;
}
