#ifndef Inferno_Graphics_GraphicsDevice
#define Inferno_Graphics_GraphicsDevice

#include "Inferno.h"
#include <vector>

#include "Graphics/ShaderType.h"
#include "Matrix.h"

namespace Inferno {
	class GameWindow;
	namespace Graphics {
		struct Color;
		struct RenderTarget;
		struct Shader;

		class INFERNO_API GraphicsDevice
		{
		    //Fields
            
            Shader* _current_fragment_shader;
            
            Shader* _current_vertex_shader;
            
            Shader* _default_fragment_shader;
            
            Shader* _default_vertex_shader;
            
            Matrix _projection_matrix;
            
            RenderTarget* _render_target;
			
			std::vector<RenderTarget*> _targets_to_dispose;

#ifdef OPENGL
	        unsigned int _gl_program;
#endif
		public:
		    //Fields
            
		    GameWindow* paired_window;
		    
			//Constructor
			
			explicit GraphicsDevice(GameWindow* window);

			//Methods
			
			void attach_shader(Shader* shader);

			void clear(Color* color);

			void delete_render_target(RenderTarget* target);
			
			void detach_shader(ShaderType type);

			void end_draw();
			
			Shader* get_current_shader(ShaderType type);
            
            Matrix get_projection_matrix();
            
            RenderTarget* get_render_target() const;
            
			void set_render_target(RenderTarget* target);
			
			int shader_get_attribute(const char* name);
            
            int shader_get_uniform(const char* name);
		};
	}
}

#endif