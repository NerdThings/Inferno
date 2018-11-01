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
		void Resizable(bool canResize);
		void SetBounds();//TODO: Rectangle struct
		void CanAltF4(bool canAltf4);
		void SetPosition(); //TODO: Point struct
		void SetTitle(const char* title);
		void SetFullscreen(bool fullscreen);
		void SetVSync(bool vsync);
		void SetCursor(bool visible);

		void BeginDraw();
		void Present();

		GameWindow(const char* title, int width, int height);
	};
}

#endif
