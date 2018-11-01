#ifndef Inferno_Game
#define Inferno_Game

#include "PlatformGame.h"
#include "GameWindow.h"
#include "Inferno.h"

namespace Inferno
{
	class INFERNO_API Game
	{
	private:
		PlatformGame *_platformGame;
		GameWindow *_gameWindow;
	public:
		//Fields
		int FramesPerSecond;

		//Constructors
		Game(int width, int height, const char* title = "Created in Inferno", int fps = 30, bool fullscreen = false);

		//Methods
		virtual void Draw();
		void Run();
		virtual void Update();
	};
}

#endif