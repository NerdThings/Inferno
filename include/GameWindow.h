#ifndef Inferno_GameWindow
#define Inferno_GameWindow

#if SDL
#include "SDL.h"
#endif

#include "Inferno.h"

namespace Inferno {
    struct Rectangle;
    struct Point;

	class INFERNO_API GameWindow {
#if SDL
		SDL_Window *_window;
#endif

		//TODO: MouseState

		//Config

		int _width;
		int _height;

	public:
	    //Constructors

        GameWindow(const char* title, int width, int height);

	    //Methods
	    
	    void end_game();

	    Rectangle get_bounds();

	    Point get_position();

	    Point get_size();

		void resizable(bool canResize);

		bool run_events() const;

		void set_bounds(Rectangle* bounds);

		void can_alt_f4(bool canAltf4);

		void set_position(Point* position);

		void set_size(Point* size);

		void set_title(const char* title);

		void set_fullscreen(bool fullscreen);

		void set_v_sync(bool vsync);

		void set_cursor(bool visible);

		void present() const;
	};
}

#endif
