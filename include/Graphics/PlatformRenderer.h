#ifndef Inferno_Graphics_PlatformRenderer
#define Inferno_Graphics_PlatformRenderer

#include "Inferno.h"

namespace Inferno
{
	struct Matrix;

	namespace Graphics
	{
		struct RenderItem;

		class INFERNO_API PlatformRenderer
		{
		public:

			//Constructor

			PlatformRenderer();

			//Methods

			void begin(Matrix* translation_matrix = nullptr) const;

			void end() const;

			void render(RenderItem* item) const;
		};
	}
}

#endif