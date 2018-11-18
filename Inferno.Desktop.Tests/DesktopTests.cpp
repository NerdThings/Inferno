#include <cstdio>
#include <cstdlib>

#include "TestGame.h"

#ifdef _WIN32
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
#else
int main()
#endif
{
	TestGame* t = new TestGame();
	t->run();
	
	delete t;
	
	return 0;
}
