#ifndef Inferno_Graphics_PlatformRenderer
#define Inferno_Graphics_PlatformRenderer

#include "Inferno.h"

namespace Inferno
{
	struct Matrix;
	namespace Graphics
	{
		class INFERNO_API PlatformRenderer
		{
		public:
			void begin(Matrix* translationMatrix);
			void end();
		};
	}
}

#endif