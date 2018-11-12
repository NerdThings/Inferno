#include "Graphics/GraphicsDevice.h"
#include "Graphics/RenderTarget.h"
#include "Graphics/Color.h"
#include "Graphics/Shader.h"
#include "Point.h"
#include "GameWindow.h"

#ifdef SDL
#include "glad/glad.h"
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {

        //Constructor

        GraphicsDevice::GraphicsDevice(GameWindow *window) : paired_window(window) {
#ifdef OPENGL
            //Create shader program
            _gl_program = glCreateProgram();
#endif
            
            //Create default shaders
            const char* GLSL_default_vertex =  "#version 330\n"
                                               "attribute vec3 inf_position;\n"
                                               "attribute vec4 inf_color;\n"
                                               "attribute vec2 inf_texcoord;\n"
                                               "uniform mat4 inf_projection_matrix;\n"
                                               "out vec4 fragColor;\n"
                                               "out vec2 texCoord;\n"
                                               "void main() {\n"
                                               "    gl_Position = inf_projection_matrix * vec4(inf_position, 1);\n"
                                               "    fragColor = inf_color;\n"
                                               "    texCoord = inf_texcoord;\n"
                                               "}";
            _default_vertex_shader = new Shader(Vertex);
            //TODO: GLSL_ES and HLSL Source
            _default_vertex_shader->set_source(GLSL_default_vertex, GLSL);
            _default_vertex_shader->compile();
            
            //TODO: Support for textures
            const char* GLSL_default_fragment = "#version 330\n"
                                                "in vec4 fragColor;\n"
                                                "in vec2 texCoord;\n"
                                                "out vec4 color;\n"
                                                "uniform sampler2D inf_texture;\n"
                                                "void main() {\n"
                                                "   color = texture(inf_texture, texCoord) * fragColor;\n"
                                                "}\n";
            
            _default_fragment_shader = new Shader(Fragment);
            _default_fragment_shader->set_source(GLSL_default_fragment, GLSL);
            _default_fragment_shader->compile();
            
            //Attach them
            attach_shader(_default_fragment_shader);
            attach_shader(_default_vertex_shader);
            
            //Orthographic matrix
            Point window_size = paired_window->get_size();
            _projection_matrix = Matrix::create_orthographic_off_center(0, window_size.x, window_size.y, 0, -1, 1);
        }

        //Methods

        void GraphicsDevice::attach_shader(Shader *shader) {
            if (shader == nullptr)
                throw "Cannot attach a null shader. Maybe you meant to call detach_shader(ShaderType)?";

            shader->type == Fragment ? _current_fragment_shader = shader : _current_vertex_shader = shader;
            
#ifdef OPENGL
            //Attach shaders to program
            glAttachShader(_gl_program, shader->shader);
            
            //Link and use program
            glLinkProgram(_gl_program);
            glUseProgram(_gl_program);
#endif
        }
        
        void GraphicsDevice::clear(Color* color) {
            if (color == nullptr)
                throw "Cannot clear with NULL.";

#ifdef OPENGL
            float r = float(color->get_r());
            glClearColor(color->get_r(), color->get_g(), color->get_b(), color->get_a());
            glClear(GL_COLOR_BUFFER_BIT);
#endif
        }

        void GraphicsDevice::delete_render_target(RenderTarget *target) {
            _targets_to_dispose.push_back(target);
        }
        
        void GraphicsDevice::detach_shader(ShaderType type) {
            type == Fragment ? _current_fragment_shader = _default_fragment_shader : _current_vertex_shader = _default_vertex_shader;
        }

        void GraphicsDevice::end_draw() {
            for (RenderTarget *target : _targets_to_dispose) {
#ifdef OPENGL
                //Unbinds
                glBindRenderbuffer(GL_RENDERBUFFER, 0);
                glBindTexture(GL_TEXTURE_2D, 0);
                glBindFramebuffer(GL_FRAMEBUFFER, 0);

                //Delete target
                glDeleteRenderbuffers(1, &target->depth_render_buffer);
                glDeleteTextures(1, &target->rendered_texture);
                glDeleteFramebuffers(1, &target->framebuffer);
#endif

                //Set all to 0
                target->depth_render_buffer = 0;
                target->rendered_texture = 0;
                target->framebuffer = 0;
            }
        }
        
        Shader* GraphicsDevice::get_current_shader(ShaderType type){
            return type == Fragment ? _current_fragment_shader : _current_vertex_shader;
        }
    
        Matrix GraphicsDevice::get_projection_matrix() {
            return _projection_matrix;
        }

        RenderTarget *GraphicsDevice::get_render_target() const {
            return _render_target;
        }

        void GraphicsDevice::set_render_target(RenderTarget *target) {
#ifdef OPENGL
            //Grab id
            unsigned int id = 0;
            if (target != NULL)
                id = target->framebuffer;

            //Bind buffer
            glBindFramebuffer(GL_FRAMEBUFFER, id);
#endif

            //Set field
            _render_target = target;
        }
        
        //TODO: Add a proper implementation for attributes and uniforms
        
        int GraphicsDevice::shader_get_attribute(const char *name) {
            return glGetAttribLocation(_gl_program, name);
        }
        
        int GraphicsDevice::shader_get_uniform(const char *name) {
            return glGetUniformLocation(_gl_program, name);
        }
    }
}