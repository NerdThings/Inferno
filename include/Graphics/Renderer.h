#ifndef Inferno_Graphics_Renderer
#define Inferno_Graphics_Renderer

#include "Inferno.h"

namespace Inferno
{
	namespace Graphics
	{
		class INFERNO_API Renderer
		{
		public:
			void Begin();
			void End();
		};
	}
}

#endif