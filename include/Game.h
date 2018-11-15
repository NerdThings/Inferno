//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_GAME_H
#define INFERNO_GAME_H

#include "Inferno.h"

#include "Graphics/Color.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        class Renderer;
    }
    
    class GameWindow;
    struct Point;
    
    class INFERNO_API Game {
    private:
        //Fields
        
        int _virtual_width;
        int _virtual_height;
        
        //Methods
        
        void begin_update();
        void do_draw();
        void do_tick();
        void draw();
        void end_update();
        void update();
        
    protected:
        //Fields
        
        Graphics::Color clear_color = Graphics::Color(255, 255, 255, 255);
        bool lock_framerate = false;
        bool paused = false;
        Graphics::Renderer* renderer = nullptr;
        bool running = false;
        
        //Methods
        
        virtual void initialise();
        
    public:
        //Fields
        
        int frames_per_second;
        GameWindow* game_window;
        Graphics::GraphicsDevice* graphics_device;
        
        //Constructors
        
        Game(int width, int height, const char* title = "Created with Inferno", int fps = 60, bool fullscreen = false);
        
        //Deconstructors
        ~Game();
        
        //Methods
        
        Point get_virtual_dimensions();
        void run();
    };
}

#endif //INFERNO_GAME_H
