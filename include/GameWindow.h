#ifndef Inferno_GameWindow
#define Inferno_GameWindow

#if SDL
#include "SDL.h"
#endif

#include "Inferno.h"

namespace Inferno
{
	class INFERNO_API GameWindow
	{
#if SDL
		SDL_Window *_window;
#endif

		//TODO: GraphicsDevice
		//TODO: MouseState

		//Config

		int _width;
		int _height;

	public:
		void resizable(bool canResize);
		void setBounds();//TODO: Rectangle struct
		void canAltF4(bool canAltf4);
		void setPosition(); //TODO: Point struct
		void setTitle(const char* title);
		void setFullscreen(bool fullscreen);
		void setVSync(bool vsync);
		void setCursor(bool visible);

		void beginDraw();
		void present();

		GameWindow(const char* title, int width, int height);
	};
}

#endif
