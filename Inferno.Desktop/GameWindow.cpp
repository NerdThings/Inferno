#include "SDL.h"
#include "SDL_opengl.h"
#include "GameWindow.h"

namespace Inferno
{
	GameWindow::GameWindow(const char* title, int width, int height)
	{
		_width = width;
		_height = height;

		//Init SDL
		_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		//Init SDL OpenGL
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
		SDL_GL_SetSwapInterval(0);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_CreateContext(_window);

		glViewport(0, 0, _width, _height);
	}

	void GameWindow::begin_draw()
	{
		glClearColor(1.0f, 0.25f, 0.5f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}


	void GameWindow::present()
	{
		SDL_GL_SwapWindow(_window);
	}
}

