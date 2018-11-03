#ifndef Inferno_Graphics_Renderer
#define Inferno_Graphics_Renderer

#include "Inferno.h"
#include <vector>
#include "RenderItem.h"

namespace Inferno
{
	struct Matrix;
	struct Rectangle;

	namespace Graphics
	{
		struct Color;
		class PlatformRenderer;

		class INFERNO_API Renderer
		{
			const PlatformRenderer* _platform_renderer;

			std::vector<RenderItem*> _batch;

			bool _rendering;

		public:
			//Constructor

			Renderer();

			//Batch controls

			void begin(Matrix* translation_matrix = nullptr);

			void end();

			//Draw methods

			void draw_rectangle(Rectangle* rect, Color* color, float depth);
		};
	}
}

#endif