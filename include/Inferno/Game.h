//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_GAME_H
#define INFERNO_GAME_H

#include "Inferno.h"

#include <string>

#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Graphics/Renderer.h"
#include "Inferno/Graphics/RenderTarget.h"
#include "Inferno/GameWindow.h"
#include "Inferno/Scene.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    /*
     * The game container
     */
    class INFERNO_API Game {
    private:
        //Fields
        
        /*
         * The current game scene
         */
        Scene* _current_scene = nullptr;
        
        /*
         * The virtual width
         */
        int _virtual_width = 0;
        
        /*
         * The virtual height
         */
        int _virtual_height = 0;
        
        //Methods
        
        /*
         * Begin update
         */
        void begin_update();
        
        /*
         * Draw
         */
        void draw();
        
        /*
         * End Update
         */
        void end_update();
        
        /*
         * Update
         */
        void update();
        
        /*
         * The update thread
         */
        void update_thread();

    protected:
        //Fields
        
        /*
         * The game clear color
         */
        Graphics::Color clear_color = Graphics::Color(255, 255, 255, 255);
        
        /*
         * Whether or not the game is paused
         */
        bool paused = false;
        
        /*
         * Whether or not the framerate is locked to the FPS value
         */
        bool locked_framerate = false;
        
        /*
         * The renderer
         */
        Graphics::Renderer* renderer = nullptr;
        
        /*
         * The game render target used for scaling
         */
        Graphics::RenderTarget* render_target = nullptr;
        
        /*
         * Whether or not the draw and update threads should run
         */
        bool running = false;
        
        //Methods
        
        /*
         * Game initialise
         */
        virtual void initialise();
        
    public:
        //Fields
        
        /*
         * How many game frames should be updated per second
         */
        int frames_per_second = 60;
        
        /*
         * The game window
         */
        GameWindow* game_window = nullptr;
        
        /*
         * The game graphics device
         */
        Graphics::GraphicsDevice* graphics_device = nullptr;
        
        //Constructors
        
        /*
         * Create a new game
         */
        Game(int width, int height, std::string title = "Created with Inferno", int fps = 60, bool fullscreen = false);
        
        //Deconstructors
        
        /*
         * Cleanup a Deleted Game
         */
        ~Game();
        
        //Methods
    
        /*
         * Get the game virtual dimensions
         */
        Vector2 get_virtual_dimensions();
        
        /*
         * Run the game
         */
        void run();
        
        /*
         * Set the game scene
         */
        void set_scene(Scene* scene);
    };
}

#endif //INFERNO_GAME_H
