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
	    
		GameWindow *_game_window;

	    bool _paused;

		Graphics::Renderer* _renderer;

		Graphics::RenderTarget* _render_target;

		Graphics::GraphicsDevice* _graphics_device;

		int _virtual_width;

		int _virtual_height;

		//Methods

		void do_draw();

		void do_tick();

	public:
		//Fields

		int frames_per_second;

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