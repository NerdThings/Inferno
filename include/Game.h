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
	    //Fields

		GameWindow *_game_window;

	    bool _paused;

		Graphics::Renderer* _renderer;

		Graphics::GraphicsDevice* _graphics_device;

		//Methods

		void do_draw();

		void do_tick();

	public:
		//Fields

		int frames_per_second;

		//Constructors

		Game(int width, int height, const char* title = "Created with Inferno", int fps = 30, bool fullscreen = false);

		//Methods

        virtual void begin_update();

        virtual void draw();

        virtual void end_update();


        void run();

		virtual void update();

	};
}

#endif