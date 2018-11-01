#include "Game.h"
#include <ctime>
#include "GameWindow.h"
#include "SDL_opengl.h"

namespace Inferno
{
	Game::Game(int width, int height, const char* title, int fps, bool fullscreen)
	{
		FramesPerSecond = fps;

		_platformGame = new PlatformGame(this);
		_gameWindow = new GameWindow(title, width, height);
	}

	void Game::Run()
	{
		int previous = ((double)clock() / CLOCKS_PER_SEC) * 1000;
		float lag = 0.0f;
		bool running = true;
		while (running)
		{
			const int current = ((double)clock() / CLOCKS_PER_SEC) * 1000;
			const int delta = current - previous;
			previous = current;
			lag += delta;

			while (lag >= 1000.0f / FramesPerSecond)
			{
				//Logic
				Update();
				lag -= 1000.0f / FramesPerSecond;

				//Inform of beginning draw
				_gameWindow->BeginDraw();

				//Draw
				Draw();

				//Present
				_gameWindow->Present();
			}

			//Run Events
			if (!_platformGame->RunEvents())
			{
				running = false;
			}
		}
	}

	void Game::Draw()
	{
		glColor3f(0.5f, 1.0f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(0, 1, 0);
		glEnd();

		glFlush();
	}

	void Game::Update()
	{
	}
}
