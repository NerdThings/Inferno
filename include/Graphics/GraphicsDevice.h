#ifndef Inferno_Graphics_GraphicsDevice
#define Inferno_Graphics_GraphicsDevice

namespace Inferno
{
	class GameWindow;
	namespace Graphics
	{
		class INFERNO_API GraphicsDevice
		{
			const GameWindow* _pairedWindow;
		public:
			void PairWindow(GameWindow *window);
			GraphicsDevice();
		};
	}
}

#endif