#ifndef Inferno_Graphics_GraphicsDevice
#define Inferno_Graphics_GraphicsDevice

#include "Inferno.h"
#include <vector>

namespace Inferno {
	class GameWindow;
	namespace Graphics {
		struct RenderTarget;

		class INFERNO_API GraphicsDevice
		{
			GameWindow* _paired_window;
			RenderTarget* _render_target;
			std::vector<RenderTarget*> _targets_to_dispose;
		public:
			//Constructor

			GraphicsDevice(GameWindow* window);

			//Methods

			void delete_render_target(RenderTarget* target);

			void end_draw();

			void set_render_target(RenderTarget* target);

			RenderTarget* get_render_target() const;
		};
	}
}

#endif