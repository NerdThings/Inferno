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
		PlatformGame *_platform_game;
		GameWindow *_game_window;
	public:
		//Fields
		int frames_per_second;

		//Constructors
		Game(int width, int height, const char* title = "Created in Inferno", int fps = 30, bool fullscreen = false);

		//Methods
		virtual void draw();
		void run();
		virtual void update();
	};
}

#endif