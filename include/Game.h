//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_GAME_H
#define INFERNO_GAME_H

#include "Inferno.h"

namespace Inferno {
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
        
        bool lock_framerate = false;
        bool paused = false;
        bool running = false;
        
    public:
        //Fields
        
        int frames_per_second;
        GameWindow* game_window;
        
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
