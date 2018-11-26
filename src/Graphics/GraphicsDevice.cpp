//
// Created by Reece Mackie on 14/11/18.
//

#include <stdexcept>

#include "Inferno/Game.h"
#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Graphics/RenderTarget.h"
#include "Inferno/Graphics/Shader.h"
#include "Inferno/Graphics/Texture2D.h"
#include "Inferno/GameWindow.h"

#ifdef OPENGL
#include "glad/glad.h"
#endif

#ifdef SDL
#include "SDL_opengl.h"
#endif

#include "IL/il.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        GraphicsDevice::GraphicsDevice(Game *game) : _parent_game(game)
        {
#ifdef OPENGL
            _gl_program = glCreateProgram();
#endif
            //Create default shaders
            //TODO: GLSL_ES and HLSL Source
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
            const char* GLSL_default_fragment = "#version 330\n"
                                                "in vec4 fragColor;\n"
                                                "in vec2 texCoord;\n"
                                                "out vec4 color;\n"
                                                "uniform sampler2D inf_texture;\n"
                                                "void main() {\n"
                                                "   vec4 texel = texture(inf_texture, texCoord);\n"
                                                "   if(texel.a == 0)\n"
                                                "       discard;\n"
                                                "   color = texel * fragColor;\n"
                                                "}\n";
            _default_vertex_shader = new Shader(Vertex);
            _default_vertex_shader->set_source(GLSL_default_vertex, GLSL);
            _default_vertex_shader->compile();
            _default_fragment_shader = new Shader(Fragment);
            _default_fragment_shader->set_source(GLSL_default_fragment, GLSL);
            _default_fragment_shader->compile();
            
            //Attach
            attach_shader(_default_vertex_shader);
            attach_shader(_default_fragment_shader);
    
            //Projection matrix
            Point window_size = _parent_game->game_window->get_size();
            _projection_matrix = Matrix::create_orthographic_off_center(0, window_size.x, window_size.y, 0, -101, 101);
            
            //View matrix
            _view_matrix = Matrix();
            
            //Init DevIL
            ilInit();
        }
        
        //Deconstructors
        
        GraphicsDevice::~GraphicsDevice() {
            //Delete default shaders
            delete _default_vertex_shader;
            delete _default_fragment_shader;
        }
        
        //Methods
        
        void GraphicsDevice::attach_shader(Shader* shader) {
            if (shader == nullptr)
                throw std::runtime_error("Cannot attach a null shader.");

#ifdef OPENGL
            //Detach existing shader]
            if (shader->type == Vertex) {
                if (_current_vertex_shader != nullptr) {
                    glDetachShader(_gl_program, _current_vertex_shader->id);
                }
            } else {
                if (_current_fragment_shader != nullptr) {
                    glDetachShader(_gl_program, _current_fragment_shader->id);
                }
            }
#endif
            
            shader->type == Vertex ? _current_vertex_shader = shader : _current_fragment_shader = shader;
            
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
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#endif
        }
        
        Matrix GraphicsDevice::get_complete_matrix() {
            return get_model_matrix() * get_view_matrix() * get_projection_matrix();
        }
        
        Matrix GraphicsDevice::get_model_matrix() {
            return _model_matrix;
        }
        
        Matrix GraphicsDevice::get_projection_matrix() {
            return _projection_matrix;
        }
        
        Matrix GraphicsDevice::get_view_matrix() {
            return _view_matrix;
        }
    
        void GraphicsDevice::pop_model_matrix() {
            if (_model_matrices.empty())
                throw std::runtime_error("No model matrix to pop.");
        
            _model_matrix = _model_matrices.at(_model_matrices.size() - 1);
            _model_matrices.pop_back();
        }
    
        void GraphicsDevice::push_model_matrix() {
            _model_matrices.emplace_back(_model_matrix);
        }
        
        void GraphicsDevice::pop_view_matrix() {
            if (_view_matrices.empty())
                throw std::runtime_error("No view matrix to pop.");
    
            _view_matrix = _view_matrices.at(_view_matrices.size() - 1);
            _view_matrices.pop_back();
        }
        
        void GraphicsDevice::push_view_matrix() {
            _view_matrices.emplace_back(_view_matrix);
        }
        
        void GraphicsDevice::set_model_matrix(Matrix model_matrix) {
            _model_matrix = model_matrix;
        }
        
        void GraphicsDevice::set_render_target(RenderTarget* target) {
            //Update projection matrix
            if (target != nullptr) {
                _projection_matrix = Matrix::create_orthographic_off_center(0, target->width, target->height, 0, -101, 101);
                glViewport(0, 0, target->width, target->height);
            } else {
                Point window_size = _parent_game->game_window->get_size();
                _projection_matrix = Matrix::create_orthographic_off_center(0, window_size.x, window_size.y, 0, -101, 101);
                glViewport(0, 0, window_size.x, window_size.y);
            }
#ifdef OPENGL
            if (target != nullptr)
                glBindFramebuffer(GL_FRAMEBUFFER, target->framebuffer);
            else
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
        }
        
        void GraphicsDevice::set_view_matrix(Matrix view_matrix) {
            _view_matrix = view_matrix;
        }
        
        //TEMP:
        
        int GraphicsDevice::shader_get_attrib(std::string attrib){
#ifdef OPENGL
            return glGetAttribLocation(_gl_program, attrib.c_str());
#endif
        }
    
        int GraphicsDevice::shader_get_uniform(std::string uniform){
#ifdef OPENGL
            return glGetUniformLocation(_gl_program, uniform.c_str());
#endif
        }
        
        void GraphicsDevice::shader_uniform_set(std::string uniform, float value) {
#ifdef OPENGL
            glUniform1f(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), value);
#endif
        }
        
        void GraphicsDevice::shader_uniform_set(std::string uniform, int value) {
#ifdef OPENGL
            glUniform1i(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), value);
#endif
        }
        
        void GraphicsDevice::shader_uniform_set(std::string uniform, Vector2 value) {
            shader_uniform_set(std::move(uniform), value.x, value.y);
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, Point value) {
            shader_uniform_set(std::move(uniform), value.x, value.y);
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, float value1, float value2) {
#ifdef OPENGL
            glUniform2f(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), value1, value2);
#endif
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, int value1, int value2) {
#ifdef OPENGL
            glUniform2i(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), value1, value2);
#endif
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, Vector3 value) {
            shader_uniform_set(std::move(uniform), value.x, value.y, value.z);
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, float value1, float value2, float value3) {
#ifdef OPENGL
            glUniform3f(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), value1, value2, value3);
#endif
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, int value1, int value2, int value3) {
#ifdef OPENGL
            glUniform3i(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), value1, value2, value3);
#endif
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, Vector4 value) {
            shader_uniform_set(std::move(uniform), value.x, value.y, value.z, value.w);
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, Color value) {
            shader_uniform_set(std::move(uniform), value.get_r(), value.get_g(), value.get_b(), value.get_a());
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, float value1, float value2, float value3, float value4) {
#ifdef OPENGL
            glUniform4f(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), value1, value2, value3, value4);
#endif
        }
    
        void GraphicsDevice::shader_uniform_set(std::string uniform, int value1, int value2, int value3, int value4) {
#ifdef OPENGL
            glUniform4i(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), value1, value2, value3, value4);
#endif
        }
        
        void GraphicsDevice::shader_uniform_set(std::string uniform, Inferno::Matrix value) {
#ifdef OPENGL
            glUniformMatrix4fv(static_cast<GLuint>(shader_get_uniform(std::move(uniform))), 1, GL_FALSE, value.to_float_vector().data());
#endif
        }

    }
}