#ifndef Inferno_Graphics_RenderItem
#define Inferno_Graphics_RenderItem

namespace Inferno {
	struct Rectangle;
	struct Vector2;

	namespace Graphics {
		struct Color;
		struct Shader;

		enum RenderType {
			texture,
			render_target,
			text,
			lines,
			rectangle,
			circle,
			filled_circle
		};

		struct RenderItem {
			//Fields

			RenderType type;
			//texture
			//rendertarget
			//font
			const char* text;
			Color* color;
			float depth;
			Rectangle* source_rectangle;
			Rectangle* destination_rectangle;
			double rotation;
			Vector2* origin;
			Vector2* verticies;
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