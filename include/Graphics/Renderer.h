#ifndef Inferno_Graphics_Renderer
#define Inferno_Graphics_Renderer

#include "Inferno.h"
#include <vector>
#include "RenderItem.h"

namespace Inferno
{
	struct Matrix;
	namespace Graphics
	{
		class PlatformRenderer;
		class INFERNO_API Renderer
		{
			const PlatformRenderer* _platformRenderer;

			std::vector<RenderItem> _batch;

			bool _rendering;

		public:
			//Constructor

			Renderer();

			//Batch controls

			void begin(Matrix* translationMatrix);

			void end();

			//Draw methods
		};
	}
}

#endif