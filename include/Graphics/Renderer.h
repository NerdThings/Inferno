#ifndef Inferno_Graphics_Renderer
#define Inferno_Graphics_Renderer

#include "Inferno.h"
#include <vector>
#include "RenderItem.h"

namespace Inferno {
	struct Matrix;
	struct Rectangle;

	namespace Graphics {
		struct Color;

		class INFERNO_API Renderer {
			//Fields

			std::vector<RenderItem*> _batch;

			bool _rendering;

#if OPENGL
			unsigned int _vertex_array;

#endif

			//Methods

			void render(RenderItem* item) const;

		public:
			//Constructor

			Renderer();

			//Batch controls

			void begin(Matrix* translation_matrix = (Matrix*)NULL);

			void end();

			//Draw methods

			void draw_rectangle(Rectangle* rect, Color* color, float depth);
		};
	}
}

#endif