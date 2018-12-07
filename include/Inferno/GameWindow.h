//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_GAMEWINDOW_H
#define INFERNO_GAMEWINDOW_H

#include <string>
#ifdef SDL
struct SDL_Window;
#endif

#include "Inferno/Rectangle.h"
#include "Inferno.h"

namespace Inferno {
    class Game;
    
    /*
     * A game window
     */
    class INFERNO_API GameWindow {
        /*
         * The parent game
         */
        Game* _parent_game;
#ifdef SDL
        /*
         * The SDL window
         */
        SDL_Window* _sdl_window;
#endif
    public:
        //Constructors
        
        /*
         * Create a new game window
         */
        GameWindow(Game* parent_game, std::string title, int width, int height);
        
        //Deconstructors
        
        /*
         * Cleanup a Deleted GameWindow
         */
        ~GameWindow();
        
        //Methods
        
        /*
         * Enable or disable alt + f4
         */
        void alt_f4(bool enabled);
        
        /*
         * Get the window bounds
         */
        Rectangle get_bounds();
        
        /*
         * Get the window position
         */
        Vector2 get_position();
        
        /*
         * Get the window size
         */
        Vector2 get_size();
        
        /*
         * Whether or not the window is resizable
         */
        void resizable(bool resizable);
        
        /*
         * Run game window events
         */
        bool run_events();
        
        /*
         * Set the window bounds
         */
        void set_bounds(Rectangle bounds);
        
        /*
         * Set if the window is fullscreen
         */
        void set_fullscreen(bool fullscreen);
        
        /*
         * Set the window position
         */
        void set_position(Vector2 position);
        
        /*
         * Set the window size
         */
        void set_size(Vector2 size);
        
        /*
         * Set the window title
         */
        void set_title(std::string title);
        
        /*
         * Enable or disable vsync
         */
        void set_v_sync(bool vsync);
        
        /*
         * Hide or Show the cursor
         */
        void set_cursor(bool visible);
        
        /*
         * Present drawings to the window
         */
        void present();
    };
}

#endif //INFERNO_GAMEWINDOW_H
