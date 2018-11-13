#ifndef Inferno_Graphics_Renderer
#define Inferno_Graphics_Renderer

#include "Inferno.h"

#include <vector>

#include "Graphics/Texture2D.h"
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
			
			Texture2D* _blank_texture = nullptr;
			
#if OPENGL
			unsigned int _vertex_array;
#endif
			
			GraphicsDevice* _graphics_device;
			
			//Methods
			
			float* build_array(std::vector<Vector2> vectors);
            
            float* build_array(std::vector<Vector3> vectors);
            
		public:
			//Constructor

			Renderer(GraphicsDevice* graphics_device);
			
			//Methods
			
			void draw_rectangle(Rectangle rect, Color color, float depth);
			
			void draw_texture(Texture2D* texture, Vector2 position, Color color, float depth);
		};
	}
}

#endif