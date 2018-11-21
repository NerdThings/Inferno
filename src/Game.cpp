//
// Created by Reece Mackie on 13/11/18.
//

#include <chrono>
#include <thread>

#include "Content/ContentLoader.h"
#include "Graphics/Color.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/Renderer.h"
#include "Graphics/RenderTarget.h"
#include "Graphics/Texture2D.h"
#include "Game.h"
#include "GameWindow.h"
#include "Scene.h"
#include "Point.h"
#include "Rectangle.h"

namespace Inferno {
    //Private Methods
    
    void Game::begin_update() {
        if (_current_scene != nullptr)
            _current_scene->begin_update();
    }
    
    void Game::draw() {
        //Get window dimensions
        Point window_size = game_window->get_size();
        
        //Set view size
        int view_width = window_size.x;
        int view_height = window_size.y;
        
        //Calculate ratios
        float output_aspect = window_size.x / float(window_size.y);
        float preferred_aspect = _virtual_width / float(_virtual_height);
        
        //Init bar dimensions
        float bar_width = 0;
        float bar_height = 0;
        
        //Calculate view
        if (output_aspect <= preferred_aspect) {
            view_height = int(window_size.x / preferred_aspect + 0.5f);
            bar_height = (window_size.y - view_height) / 2;
        } else {
            view_width = int(window_size.y * preferred_aspect + 0.5f);
            bar_width = (window_size.x - view_width) / 2;
        }
        
        //Clear outer zone
        graphics_device->clear(Graphics::Color(0, 0, 0, 255));
        
        //Render to target
        graphics_device->set_render_target(render_target);
    
        //Clear target
        graphics_device->clear(clear_color);
    
        //Draw current scene
        if (_current_scene != nullptr)
            _current_scene->draw(renderer);
        
        //Unset target
        graphics_device->set_render_target(nullptr);
        
        //Draw target
        renderer->draw_render_target(render_target, Rectangle(bar_width, bar_height, view_width, view_height), Graphics::Color(255, 255, 255, 255), 0);
    }
    
    void Game::end_update() {
        if (_current_scene != nullptr)
            _current_scene->end_update();
    }
    
    void Game::update() {
        if (_current_scene != nullptr)
            _current_scene->update();
    }

#define CLOCKS_PER_MS CLOCKS_PER_SEC * 1000
    
    int get_time() {
        auto time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::millisecond>(time);
    }
    
    void Game::update_thread() {
        //Begin loop
        int previous = get_time();
        float lag = 0.0f;
        running = true;
    
        //Run an initial tick
        begin_update();
        update();
        end_update();
    
        while (running) {
            int current = get_time();
            const float delta = current - previous;
            previous = current;
            lag += delta;
        
            while (lag >= 1000.0f / frames_per_second) {
                lag -= 1000.0f / frames_per_second;
    
                if (paused)
                    return;
    
                //Run an update
                begin_update();
                update();
                end_update();
            }
        }
    }
    
    //Protected Methods
    void Game::initialise() {
    }
    
    //Constructors
    
    Game::Game(int width, int height, std::string title, int fps, bool fullscreen) : _virtual_width(width), _virtual_height(height), frames_per_second(fps) {
        //Create window
        game_window = new GameWindow(this, title, width, height);
        
        //Create graphics device
        graphics_device = new Graphics::GraphicsDevice(this);
        
        //Create renderer
        renderer = new Graphics::Renderer(graphics_device);
        
        //Create main render target
        render_target = new Graphics::RenderTarget(graphics_device, _virtual_width, _virtual_height);
    
        //Set properties
        game_window->set_fullscreen(fullscreen);
        paused = false;
        running = false;
    }
    
    //Deconstructors
    
    Game::~Game() {
    
    }
    
    //Methods
    
    Point Game::get_virtual_dimensions() {
        return {_virtual_width, _virtual_height};
    }
    
    void Game::run() {
        //Run init
        initialise();
        
        //Launch update thread
        std::thread thread(&Game::update_thread, this);
        
        //Begin draw loop
        int previous = get_time();
        float lag = 0.0f;
        running = true;
        
        while (running) {
            int current = get_time();
            const float delta = current - previous;
            previous = current;
            lag += delta;
            
            while (lag >= 1000.0f / frames_per_second) {
                lag -= 1000.0f / frames_per_second;

                if (locked_framerate) {
                    //Draw
                    draw();
    
                    //Present
                    game_window->present();
    
                    //End draw
                    graphics_device->end_draw();
                }
            }
    
            //Run window events
            if (!game_window->run_events())
                running = false;
            
            if (!locked_framerate) {
                //Draw
                draw();
    
                //Present
                game_window->present();
    
                //End draw
                graphics_device->end_draw();
            }
        }
        
        //Wait for update thread to finish
        thread.join();
    
        //Fix for the linux resolution bug
        game_window->set_fullscreen(false);
    
        //Unload current scene
        if (_current_scene != nullptr) {
            _current_scene->unloaded();
            _current_scene = nullptr;
        }
    
        //Delete render target
        delete render_target;
        render_target = nullptr;
    
        //Delete renderer
        delete renderer;
        renderer = nullptr;
    
        //Delete graphics device
        delete graphics_device;
        graphics_device = nullptr;
    
        //Delete game window
        delete game_window;
        game_window = nullptr;
    }
    
    void Game::set_scene(Inferno::Scene *scene) {
        //Unload current scene
        if (_current_scene != nullptr)
            _current_scene->unloaded();
        
        //Update scene
        _current_scene = scene;
        
        //Load new scene
        if (_current_scene != nullptr)
            _current_scene->loaded();
    }
}
