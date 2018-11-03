#ifndef Inferno_Graphics_RenderItem
#define Inferno_Graphics_RenderItem

namespace Inferno
{
	struct Rectangle;
	struct Vector2;
	namespace Graphics
	{
		enum RenderType
		{
			texture,
			renderTarget,
			text,
			lines,
			rectangle,
			circle,
			filledCircle
		};

		struct RenderItem
		{
			RenderType type;
			//texture
			//rendertarget
			//font
			const char* text;
			//color
			float depth;
			Rectangle* sourceRectangle;
			Rectangle* destinationRectangle;
			double rotation;
			Vector2* origin;
			Vector2* verticies;
			bool dispose;
			int lineWidth;
			int radius;
			int precision;
		};
	}
}

#endif