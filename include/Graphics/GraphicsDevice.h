#ifndef Inferno_Graphics_GraphicsDevice
#define Inferno_Graphics_GraphicsDevice

#include "Inferno.h"

namespace Inferno
{
	class GameWindow;
	namespace Graphics
	{
		class INFERNO_API GraphicsDevice
		{
			const GameWindow* _paired_window;
		public:
			void pair_window(GameWindow *window);
			GraphicsDevice();
		};
	}
}

#endif