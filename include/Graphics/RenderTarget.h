#ifndef Inferno_Graphics_RenderTarget
#define Inferno_Graphics_RenderTarget

#include "Inferno.h"

namespace Inferno
{
	namespace Graphics
	{
		struct INFERNO_API RenderTarget
		{
			//Fields

			const int width;
			const int height;

#ifdef OPENGL
			unsigned int framebuffer;
			unsigned int rendered_texture;
			unsigned int depth_render_buffer;
#endif

			//Constructors

			RenderTarget(int _width, int _height);

			//Deconstructors

			~RenderTarget();
		};
	}
}

#endif