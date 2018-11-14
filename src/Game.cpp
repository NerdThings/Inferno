//
// Created by Reece Mackie on 13/11/18.
//

#include <ctime>

#include "Graphics/Color.h"
#include "Graphics/GraphicsDevice.h"
#include "Game.h"
#include "GameWindow.h"
#include "Point.h"

namespace Inferno {
    //Private Methods
    
    void Game::begin_update() {
    
    }
    
    void Game::do_draw() {
        if (paused | lock_framerate)
            return;
    
        //Draw frame
        draw();
    
        //Present
        game_window->present();
        
        //End draw
        graphics_device->end_draw();
    }
    
    void Game::do_tick() {
        if (paused)
            return;
    
        //Run an update
        begin_update();
        update();
        end_update();
    
        //Draw a frame if the framerate is locked
        if (lock_framerate) {
            //Draw
            draw();
        
            //Present
            game_window->present();
            
            //End draw
            graphics_device->end_draw();
        }
    }
    
    void Game::draw() {
        graphics_device->clear(Graphics::Color(255, 255, 255, 255));
    }
    
    void Game::end_update() {
    
    }
    
    void Game::update() {
    
    }
    
    //Protected Methods
    void Game::initialise() {
    
    }
    
    //Constructors
    
    Game::Game(int width, int height, const char *title, int fps, bool fullscreen) : _virtual_width(width), _virtual_height(height), frames_per_second(fps) {
        //Create window
        game_window = new GameWindow(this, title, width, height);
        
        //Create graphics device
        graphics_device = new Graphics::GraphicsDevice(this);
    
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
        int previous = int(double(clock()) / CLOCKS_PER_SEC) * 1000;
        float lag = 0.0f;
        running = true;
        while (running) {
            const int current = int(double(clock()) / CLOCKS_PER_SEC) * 1000;
            const int delta = current - previous;
            previous = current;
            lag += delta;
            
            while (lag >= 1000.0f / frames_per_second) {
                //Run a tick
                do_tick();
                
                lag -= 1000.f / frames_per_second;
            }
            
            //Draw a frame
            do_draw();
            
            //Run window events
            if (!game_window->run_events()) {
                running = false;
            }
        }
        
        //Fix for the linus resolution bug
        game_window->set_fullscreen(false);
    
        //Run another end draw to delete anything else before deleting graphics device
        graphics_device->end_draw();
        
        //Delete graphics device
        delete graphics_device;
        graphics_device = nullptr;
        
        //Delete game window
        delete game_window;
        game_window = nullptr;
    }
}