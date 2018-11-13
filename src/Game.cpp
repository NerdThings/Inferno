#include "Game.h"
#include <ctime>
#include "GameWindow.h"
#include "Graphics/Renderer.h"
#include "Graphics/RenderTarget.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/Color.h"
#include "Point.h"
#include "Scene.h"

namespace Inferno {
	using namespace Graphics;

	void Game::do_draw() {
	    //Skip if paused
	    if (_paused)
	        return;

        //Draw
        draw();

        //present
        game_window->present();
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

	Game::Game(int width, int height, const char* title, int fps, bool fullscreen) : virtual_width(width), virtual_height(height), frames_per_second(fps) {
	    //Create window
		game_window = new GameWindow(title, width, height);

		//Create and attach graphics device
		_graphics_device = new GraphicsDevice(game_window);

		//Create renderer
		_renderer = new Renderer(_graphics_device);

		//Create render target
		_render_target = new RenderTarget(_graphics_device, width, height); //TODO: Remake this once the window is resized

		//Set properties
		game_window->set_fullscreen(fullscreen);
		_paused = false; //TODO: Set to window focus status once we have capabilities
	}

	void Game::run() {
		int previous = int(double(clock()) / CLOCKS_PER_SEC) * 1000;
		float lag = 0.0f;
		bool running = true;
		while (running) {
		    auto tmb = (double)clock() / CLOCKS_PER_SEC;
            const int current = (int)(((double)clock() / CLOCKS_PER_SEC) * 1000);
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
			if (!game_window->run_events()) {
				running = false;
			}
		}
		
		//Fix the linux resolution bug
		game_window->set_fullscreen(false);
		
		//Send end game
		game_window->end_game();
	}
	
	void Game::set_scene(Inferno::Scene* scene) {
		//Unload current scene if it exists
		if (_current_scene != nullptr)
			_current_scene->unloaded();
		
		//Set the new scene
		_current_scene = scene;
		
		//Load current scene if it exists
		if (_current_scene != nullptr)
		    _current_scene->loaded();
	}

	void Game::begin_update() {
        if (_current_scene != nullptr)
            _current_scene->begin_update();
	}

	void Game::draw() {
	    //Grab dimensions
	    Point size = game_window->get_size();
	    int window_width = size.x;
	    int window_height = size.y;

	    int view_width = window_width;
	    int view_height = window_height;

	    //Calculate ratios
        float output_aspect = float(view_width) / float(view_height);
        float preferred_aspect = float(virtual_width) / float(virtual_height);

        //Init bar dimensions
        int bar_width = 0;
        int bar_height = 0;

        //Calculate bar dimensions
        if (output_aspect <= preferred_aspect) {
            view_height = int(window_width / preferred_aspect + 0.5f);
            bar_height = int((window_height / view_height) / 2.0f);
        } else {
            view_width = int(window_height * preferred_aspect + 0.5f);
            bar_width = int((window_width - view_width) / 2.0f);
        }

        //Clear outside of the logical window
        _graphics_device->clear(new Color(0, 0, 0, 1));

        //Set render target
        //_graphics_device->set_render_target(_render_target);

        //Clear target
        //_graphics_device->clear(new Color(0.25f, 0.5f, 0.75f, 1.0f)); //TODO: ClearColor variable

        //Draw scene
        

        //Reset target
        _graphics_device->set_render_target(nullptr);
        
        //Draw the render target
        //_renderer->begin();
        //TODO
        //_renderer->end();
    }

    void Game::end_update() {
        if (_current_scene != nullptr)
            _current_scene->end_update();
	}
	
	Point Game::get_virtual_dimensions() const {
		return {virtual_width, virtual_height};
	}

	void Game::update() {
        if (_current_scene != nullptr)
            _current_scene->update();
	}
}
