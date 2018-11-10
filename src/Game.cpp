#include "Game.h"
#include <ctime>
#include "GameWindow.h"
#include "Graphics/Renderer.h"
#include "Graphics/GraphicsDevice.h"

namespace Inferno {
	using namespace Graphics;

	Game::Game(int width, int height, const char* title, int fps, bool fullscreen) {
		frames_per_second = fps;

		_game_window = new GameWindow(title, width, height);
		_graphics_device = new GraphicsDevice(_game_window);
		_renderer = new Renderer();
	}

	void Game::run() {
		int previous = (int)((double)clock() / CLOCKS_PER_SEC) * 1000;
		float lag = 0.0f;
		bool running = true;
		while (running) {
			const int current = (int)((double)clock() / CLOCKS_PER_SEC) * 1000;
			const int delta = current - previous;
			previous = current;
			lag += delta;

			while (lag >= 1000.0f / frames_per_second) {
				//Logic
				update();
				lag -= 1000.0f / frames_per_second;

				//Inform of beginning draw
				_game_window->begin_draw();

				//Draw
				draw();

				//present
				_game_window->present();
			}

			//Run Events
			if (!_game_window->run_events()) {
				running = false;
			}
		}
	}

	void Game::draw() {
		
	}

	void Game::update() {
	}
}
