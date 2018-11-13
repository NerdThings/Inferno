//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_GAMEWINDOW_H
#define INFERNO_GAMEWINDOW_H

#include "Inferno.h"

#ifdef SDL
struct SDL_Window;
#endif

namespace Inferno {
    struct Game;
    struct Point;
    struct Rectangle;
    
    class INFERNO_API GameWindow {
        Game* _parent_game;
#ifdef SDL
        SDL_Window* _sdl_window;
#endif
    public:
        //Constructors
        
        GameWindow(Game* parent_game, const char* title, int width, int height);
        
        //Deconstructors
        
        ~GameWindow();
        
        //Methods
        
        void alt_f4(bool enabled);
        Rectangle get_bounds();
        Point get_position();
        Point get_size();
        void resizable(bool resizable);
        bool run_events();
        void set_bounds(Rectangle bounds);
        void set_fullscreen(bool fullscreen);
        void set_position(Point position);
        void set_size(Point size);
        void set_title(const char* title);
        void set_v_sync(bool vsync);
        void set_cursor(bool visible);
        void present();
    };
}

#endif //INFERNO_GAMEWINDOW_H
