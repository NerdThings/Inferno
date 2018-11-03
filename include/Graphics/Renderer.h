#ifndef Inferno_Graphics_Renderer
#define Inferno_Graphics_Renderer

#include "Inferno.h"

namespace Inferno
{
	struct Matrix;
	namespace Graphics
	{
		class PlatformRenderer;
		class INFERNO_API Renderer
		{
			const PlatformRenderer* _platformRenderer;
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