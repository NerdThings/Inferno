#include "SDL.h"
#include "glad/glad.h"
#include "SDL_opengl.h"
#include "GameWindow.h"

namespace Inferno {
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

#endif
	}

	void GameWindow::present() const {
#ifdef SDL

		SDL_GL_SwapWindow(_window);

#endif
	}
}

