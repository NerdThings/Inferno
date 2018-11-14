//
// Created by Reece Mackie on 14/11/18.
//

#include "Game.h"
#include "Graphics/Color.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/RenderTarget.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture2D.h"
#include "GameWindow.h"

#ifdef OPENGL
#include "glad/glad.h"
#endif

#ifdef SDL
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        GraphicsDevice::GraphicsDevice(Game *game) : _parent_game(game)
        {
#ifdef OPENGL
            _gl_program = glCreateProgram();
#endif
            //Create default shaders
            const char* GLSL_default_vertex =  "#version 330\n"
                                               "attribute vec3 inf_position;\n"
                                               "attribute vec4 inf_color;\n"
                                               "attribute vec2 inf_texcoord;\n"
                                               "uniform mat4 inf_matrix;\n"
                                               "out vec4 fragColor;\n"
                                               "out vec2 texCoord;\n"
                                               "void main() {\n"
                                               "    gl_Position = inf_matrix * vec4(inf_position, 1);\n"
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
    
            //Projection matrix
            Point window_size = _parent_game->game_window->get_size();
            _projection_matrix = Matrix::create_orthographic_off_center(0, window_size.x, window_size.y, 0, -1, 1);
            
            //View matrix
            _view_matrix = Matrix();
        }
        
        //Deconstructors
        
        GraphicsDevice::~GraphicsDevice() {
            //TODO: Delete loaded shaders
        }
        
        //Methods
        
        void GraphicsDevice::attach_shader(Shader* shader) {
            if (shader == nullptr)
                throw "Cannot attach a null shader.";
    
            shader->type == Fragment ? _current_fragment_shader = shader : _current_vertex_shader = shader;

#ifdef OPENGL
            //Attach shaders to program
            glAttachShader(_gl_program, shader->id);
    
            //Link and use program
            glLinkProgram(_gl_program);
            glUseProgram(_gl_program);
#endif
        }
        
        void GraphicsDevice::clear(Color color) {
#ifdef OPENGL
            glClearColor(color.get_r(), color.get_g(), color.get_b(), color.get_a());
            glClear(GL_COLOR_BUFFER_BIT);
#endif
        }
        
        void GraphicsDevice::delete_render_target(Inferno::Graphics::RenderTarget *target) {
            //Check not null
            if (target == nullptr)
                throw "Cannot delete a null target";
            
            //Queue to be destroyed
            _queue_rendertarget.emplace_back(target);
        }
        
        void GraphicsDevice::delete_shader(Shader *shader) {
            //Check not null
            if (shader == nullptr)
                throw "Cannot delete a null shader";
            
            //Check not active
            if (shader->id == _current_vertex_shader->id || shader->id == _current_fragment_shader->id)
                throw "Cannot delete a shader while it is in use";
            
            //Queue the shader to be destroyed
            _queue_shader.emplace_back(shader);
        }
        
        void GraphicsDevice::delete_texture2d(Inferno::Graphics::Texture2D *texture) {
            //Check not null
            if (texture == nullptr)
                throw "Cannot delete a null texture";
            
            //Queue to be destroyed
            _queue_texture2d.emplace_back(texture);
        }
        
        void GraphicsDevice::end_draw() {
            //Delete render targets
            for (RenderTarget* target : _queue_rendertarget) {
#ifdef OPENGL
                //Unbinds
                glBindRenderbuffer(GL_RENDERBUFFER, 0);
                glBindTexture(GL_TEXTURE_2D, 0);
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
                //Delete OpenGL target
                glDeleteRenderbuffers(1, &target->depth_render_buffer);
                glDeleteTextures(1, &target->rendered_texture);
                glDeleteFramebuffers(1, &target->framebuffer);
                
                //Unset ids
                target->depth_render_buffer = 0;
                target->rendered_texture = 0;
                target->framebuffer = 0;
#endif
            }
            
            //Delete shaders
            for (Shader* shader : _queue_shader) {
#ifdef OPENGL
                //Delete OpenGL Shader
                glDeleteShader(shader->id);
                
                //Unset shader id
                shader->id = 0;
#endif
                //Don't delete from memory, allow user to do it.
            }
            
            //Delete textures
            for (Texture2D* texture : _queue_texture2d) {
#ifdef OPENGL
                //Unbind textures
                glBindTexture(GL_TEXTURE_2D, 0);
                
                //Delete OpenGL Texture
                glDeleteTextures(1, &texture->id);
                
                //Unset id
                texture->id = 0;
#endif
            }
            
            //Clear queues
            _queue_rendertarget.clear();
            _queue_shader.clear();
            _queue_texture2d.clear();
        }
        
        Matrix GraphicsDevice::get_complete_matrix() {
            return get_projection_matrix() * get_view_matrix();
        }
        
        Matrix GraphicsDevice::get_projection_matrix() {
            return _projection_matrix;
        }
        
        Matrix GraphicsDevice::get_view_matrix() {
            return _view_matrix;
        }
        
        void GraphicsDevice::set_view_matrix(Matrix view_matrix) {
            _view_matrix = view_matrix;
        }
        
        //TEMP:
        
        int GraphicsDevice::shader_get_attrib(const char *attrib){
#ifdef OPENGL
            return glGetAttribLocation(_gl_program, attrib);
#endif
        }
    
        int GraphicsDevice::shader_get_uniform(const char *uniform){
#ifdef OPENGL
            return glGetUniformLocation(_gl_program, uniform);
#endif
        }
    }
}