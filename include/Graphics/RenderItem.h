#ifndef Inferno_Graphics_RenderItem
#define Inferno_Graphics_RenderItem

#include "Inferno.h"

#include <vector>

#include "Graphics/Color.h"
#include "Rectangle.h"
#include "Vector2.h"

namespace Inferno {
	struct Rectangle;
	struct Vector2;

	namespace Graphics {
		struct Color;
		struct Shader;

		enum RenderType {
		    nothing,
			texture,
			render_target,
			text,
			lines,
			rectangle,
			circle,
			filled_circle
		};

		struct RenderItem {
			//Constructor
			
			RenderItem();
			
			//Fields

			RenderType type;
			//texture
			//rendertarget
			//font
			const char* text;
			Color color;
			float depth;
			Rectangle source_rectangle;
			Rectangle destination_rectangle;
			double rotation;
			Vector2 origin;
            std::vector<Vector2> verticies;
            bool dispose;
			int line_width;
			int radius;
			int precision;
			
			Shader* fragment_shader;
			Shader* vertex_shader;
		};
	}
}

#endif