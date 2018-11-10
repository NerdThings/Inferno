#ifndef Inferno_Game
#define Inferno_Game

#include "Inferno.h"

namespace Inferno {
	namespace Graphics {
		class Renderer;
		class GraphicsDevice;
	}

	class PlatformGame;
	class GameWindow;	

	class INFERNO_API Game {
	protected:
		GameWindow *_game_window;
		Graphics::Renderer* _renderer;
		Graphics::GraphicsDevice* _graphics_device;
	public:
		//Fields
		int frames_per_second;

		//Constructors
		Game(int width, int height, const char* title = "Created with Inferno", int fps = 30, bool fullscreen = false);

		//Methods
		virtual void draw();
		void run();
		virtual void update();
	};
}

#endif