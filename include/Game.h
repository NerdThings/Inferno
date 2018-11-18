//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_GAME_H
#define INFERNO_GAME_H

#include "Inferno.h"

#include <string>

#include "Graphics/Color.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        class Renderer;
        struct RenderTarget;
    }
    
    class GameWindow;
    struct Point;
    class Scene;
    
    class INFERNO_API Game {
    private:
        //Fields
        
        Scene* _current_scene = nullptr;
        int _virtual_width = 0;
        int _virtual_height = 0;
        
        //Methods
        
        void begin_update();
        void do_tick();
        void draw();
        void end_update();
        void update();
        
    protected:
        //Fields
        
        Graphics::Color clear_color = Graphics::Color(255, 255, 255, 255);
        bool paused = false;
        Graphics::Renderer* renderer = nullptr;
        Graphics::RenderTarget* render_target = nullptr;
        bool running = false;
        
        //Methods
        
        virtual void initialise();
        
    public:
        //Fields
        
        int frames_per_second = 60;
        GameWindow* game_window = nullptr;
        Graphics::GraphicsDevice* graphics_device = nullptr;
        
        //Constructors
        
        Game(int width, int height, std::string title = "Created with Inferno", int fps = 60, bool fullscreen = false);
        
        //Deconstructors
        ~Game();
        
        //Methods
        
        Point get_virtual_dimensions();
        void run();
        void set_scene(Scene* scene);
    };
}

#endif //INFERNO_GAME_H
