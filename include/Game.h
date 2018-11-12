#ifndef Inferno_Game
#define Inferno_Game

#include "Inferno.h"

#include "Point.h"

namespace Inferno {
	namespace Graphics {
		class Renderer;
		class GraphicsDevice;
		struct RenderTarget;
	}

	class GameWindow;
	class Scene;

	class INFERNO_API Game {
	protected:
	    //Fields

	    Scene* _current_scene;

	    bool _paused;

		Graphics::Renderer* _renderer;

		Graphics::RenderTarget* _render_target;

		Graphics::GraphicsDevice* _graphics_device;

		//Methods

		void do_draw();

		void do_tick();

	public:
		//Fields

		int frames_per_second;
        
        GameWindow *game_window;
        
        const int virtual_width;
        
        const int virtual_height;

		//Constructors

		Game(int width, int height, const char* title = "Created with Inferno", int fps = 30, bool fullscreen = false);

		//Methods

        virtual void begin_update();

        virtual void draw();

        virtual void end_update();
        
        Point get_virtual_dimensions() const;

        void run();
        
        void set_scene(Scene* scene);

		virtual void update();

	};
}

#endif