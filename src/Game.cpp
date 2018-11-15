//
// Created by Reece Mackie on 13/11/18.
//

#include <ctime>

#include "Content/ContentLoader.h"
#include "Graphics/Color.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/Renderer.h"
#include "Graphics/RenderTarget.h"
#include "Graphics/Texture2D.h"
#include "Game.h"
#include "GameWindow.h"
#include "Point.h"
#include "Rectangle.h"

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
    
    //Test globals:
    Graphics::Texture2D* tmb = nullptr;
    Graphics::RenderTarget* tmb1 = nullptr;
    
    void Game::draw() {
        //The following is test code
        if (tmb == nullptr)
            tmb = Content::ContentLoader::load_texture(graphics_device, "/home/reece/test.png");
        
        if (tmb1 == nullptr)
            tmb1 = new Graphics::RenderTarget(graphics_device, 100, 100);
        
        graphics_device->set_render_target(tmb1);
        renderer->draw_rectangle(Rectangle(0, 0, 100, 100), Graphics::Color(0, 0, 255, 255), 0);
        graphics_device->set_render_target(nullptr);
        
        graphics_device->clear(Graphics::Color(255, 255, 255, 255));
        renderer->draw_rectangle(Rectangle(10, 10, 50, 50), Graphics::Color(0, 255, 0, 255), 0);
        renderer->draw_texture(tmb, Rectangle(60, 60, 60, 60), Graphics::Color(255, 255, 255, 255), 0);
        //renderer->draw_render_target(tmb1, Vector2(60, 60), Graphics::Color(255, 255, 255, 255), 0);
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
        
        //Create renderer
        renderer = new Graphics::Renderer(graphics_device);
    
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
        
        //Begin loop
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
}