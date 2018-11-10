#ifndef Inferno_GameWindow
#define Inferno_GameWindow

#if SDL
#include "SDL.h"
#endif

#include "Inferno.h"

namespace Inferno {
	class INFERNO_API GameWindow {
#if SDL
		SDL_Window *_window;
#endif

		//TODO: GraphicsDevice
		//TODO: MouseState

		//Config

		int _width;
		int _height;

	public:
		void resizable(bool canResize);
		bool run_events() const;
		void set_bounds();//TODO: Rectangle struct
		void can_alt_f4(bool canAltf4);
		void set_position(); //TODO: Point struct
		void set_title(const char* title);
		void set_fullscreen(bool fullscreen);
		void set_v_sync(bool vsync);
		void set_cursor(bool visible);

		void present() const;

		GameWindow(const char* title, int width, int height);
	};
}

#endif
