#include "Rectangle.h"
#include "SDL.h"
#include "glad/glad.h"
#include "SDL_opengl.h"
#include "GameWindow.h"
#include "Point.h"

namespace Inferno {

	//Constructor

	GameWindow::GameWindow(const char* title, int width, int height) {
		_width = width;
		_height = height;

#ifdef SDL

		//Init SDL
		if (SDL_Init(SDL_INIT_EVERYTHING))
			throw "SDL Failed to init";

		//Create window
		_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
								   SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		//Init SDL OpenGL
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
		SDL_GL_SetSwapInterval(0);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_CreateContext(_window);

#endif

#ifdef OPENGL

		//Load glad
		gladLoadGL();

		//Set viewport
		glViewport(0, 0, _width, _height);
		
		//Enable blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

#endif
	}

	//Methods

	Rectangle* GameWindow::get_bounds() {
	    Point* pos = get_position();
	    Point* size = get_size();
	    return new Rectangle(pos->x, pos->y, size->x, size->y);
	}

	Point* GameWindow::get_position() {
        int x = 0, y = 0;
        SDL_GetWindowPosition(_window, &x, &y);
        return new Point(x, y);
	}

	Point* GameWindow::get_size() {
	    int w = 0, h = 0;
	    SDL_GetWindowSize(_window, &w, &h);
        return new Point(w, h);
    }

	void GameWindow::resizable(bool canResize) {
#ifdef SDL
	    
	    SDL_SetWindowResizable(_window, (SDL_bool)canResize);
	    
#endif
	}

    bool GameWindow::run_events() const {
#ifdef SDL

        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                return false;
            }
        }

        return true;

#endif
    }

	void GameWindow::set_bounds(Inferno::Rectangle *bounds) {
	    set_position(new Point(bounds->x, bounds->y));
	    set_size(new Point(bounds->width, bounds->height));
	}

	void GameWindow::can_alt_f4(bool canAltf4){
#ifdef SDL

	    SDL_SetHint(SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4, canAltf4 ? "0" : "1");

#endif
	}

	void GameWindow::set_position(Inferno::Point *position) {
#ifdef SDL

	    SDL_SetWindowPosition(_window, position->x, position->y);

#endif
	}

	void GameWindow::set_size(Inferno::Point *size) {
#ifdef SDL

	    SDL_SetWindowSize(_window, size->x, size->y);

#endif
	}

	void GameWindow::set_title(const char *title) {
#ifdef SDL

	    SDL_SetWindowTitle(_window, title);

#endif
	}

	void GameWindow::set_fullscreen(bool fullscreen) {
#ifdef SDL

	    SDL_SetWindowFullscreen(_window, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);

#endif
	}

	void GameWindow::set_v_sync(bool vsync) {
#ifdef SDL && OPENGL

	    SDL_GL_SetSwapInterval(vsync? 1 : 0);

#endif
	}

	void GameWindow::set_cursor(bool visible) {
#ifdef SDL

	    SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);

#endif
	}

    void GameWindow::present() const {
#ifdef SDL

        SDL_GL_SwapWindow(_window);

#endif
    }
}

