#ifndef Inferno_Graphics_Renderer
#define Inferno_Graphics_Renderer

#include "Inferno.h"
#include <vector>
#include "RenderItem.h"
#include "Matrix.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Inferno {
	struct Matrix;
	struct Rectangle;

	namespace Graphics {
		struct Color;
		class GraphicsDevice;

		class INFERNO_API Renderer {
			//Fields

			std::vector<RenderItem> _batch;

			bool _rendering;

#if OPENGL
			unsigned int _vertex_array;
			
			unsigned int _gl_program;

#endif
			
			GraphicsDevice* _graphics_device;
			
			Matrix _translation_matrix;

			//Methods
			
			float* build_array(std::vector<Vector2> vectors);
            
            float* build_array(std::vector<Vector3> vectors);

			void render(RenderItem item);

		public:
			//Constructor

			Renderer(GraphicsDevice* graphics_device);

			//Batch controls
			
			void begin();

			void begin(Matrix translation_matrix);

			void end();

			//Draw methods

			void draw_rectangle(Rectangle rect, Color color, float depth);
		};
	}
}

#endif