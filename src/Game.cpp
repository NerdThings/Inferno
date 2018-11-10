#include "Game.h"
#include <ctime>
#include "GameWindow.h"
#include "Graphics/Renderer.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/Color.h"

namespace Inferno {
	using namespace Graphics;

	void Game::do_draw() {
	    //Skip if paused
	    if (_paused)
	        return;

        //Draw
        draw();

        //present
        _game_window->present();
	}

	void Game::do_tick() {
	    //Skip if paused
	    if (_paused)
	        return;

	    //Run an update
	    begin_update();
	    update();
	    end_update();
	}

	Game::Game(int width, int height, const char* title, int fps, bool fullscreen) {
		frames_per_second = fps;

		_game_window = new GameWindow(title, width, height);
		_graphics_device = new GraphicsDevice(_game_window);
		_renderer = new Renderer();

		_paused = false; //TODO: Set to window focus status once we have capabilities
	}

	void Game::run() {
		int previous = int(double(clock()) / CLOCKS_PER_SEC) * 1000;
		float lag = 0.0f;
		bool running = true;
		while (running) {
			const int current = int(double(clock()) / CLOCKS_PER_SEC) * 1000;
			const int delta = current - previous;
			previous = current;
			lag += delta;

			while (lag >= 1000.0f / frames_per_second) {
				//Run a single frame tick
				do_tick();

				lag -= 1000.0f / frames_per_second;
			}

            do_draw();

			//Run Events
			if (!_game_window->run_events()) {
				running = false;
			}
		}
	}

	void Game::begin_update() {

	}

	void Game::draw() {

	    //TODO: Replace this with DPI independancy system
        _graphics_device->clear(new Color(1.0f, 1.0f, 1.0f, 1.0f));
    }

    void Game::end_update() {

	}

	void Game::update() {
	}
}
