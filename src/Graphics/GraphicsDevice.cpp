//
// Created by Reece Mackie on 14/11/18.
//

#include "Inferno/Game.h"
#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Graphics/RenderTarget.h"
#include "Inferno/Graphics/Shader.h"
#include "Inferno/Graphics/Texture2D.h"
#include "Inferno/GameWindow.h"

#ifdef OPENGL
#include <glad/glad.h>
#endif

#ifdef SDL
#include <SDL_opengl.h>
#endif

#include <IL/il.h>
#include <stdexcept>

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        GraphicsDevice::GraphicsDevice(Game *game) : _parent_game(game)
        {
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
            //Create and compile shader
            default_shader = new Shader();
            default_shader->set_source(Vertex, GLSL_default_vertex, GLSL);
            default_shader->set_source(Fragment, GLSL_default_fragment, GLSL);
            default_shader->compile();
            
            //Use new shader
            use_shader(default_shader);
            
            //Projection matrix
            Vector2 window_size = _parent_game->game_window->get_size();
            _projection_matrix = Matrix::create_orthographic_off_center(0, window_size.x, window_size.y, 0, -101, 101);
            
            //View matrix
            _view_matrix = Matrix();
            
            //Init DevIL
            ilInit();
        }
        
        //Deconstructors
        
        GraphicsDevice::~GraphicsDevice() {
            //Delete default shader
            delete default_shader;
        }
        
        //Methods
        
        void GraphicsDevice::clear(Color color) {
#ifdef OPENGL
            glClearColor(color.r(), color.g(), color.b(), color.a());
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#endif
        }
        
        Matrix GraphicsDevice::get_complete_matrix() {
            return get_model_matrix() * get_view_matrix() * get_projection_matrix();
        }
        
        Shader* GraphicsDevice::get_current_shader() {
            return _shader;
        }
        
        RenderTarget* GraphicsDevice::get_current_target() {
            return _render_target;
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
    
        void GraphicsDevice::pop_render_target() {
            if (_render_targets.empty())
                throw std::runtime_error("No model matrix to pop.");
    
            set_render_target(_render_targets.at(_render_targets.size() - 1));
            _render_targets.pop_back();
        }
    
        void GraphicsDevice::push_render_target() {
            _render_targets.emplace_back(_render_target);
        }
    
        void GraphicsDevice::pop_shader(){
            if (_shaders.empty())
                throw std::runtime_error("No model matrix to pop.");
        
            use_shader(_shaders.at(_shaders.size() - 1));
            _shaders.pop_back();
        }
    
        void GraphicsDevice::push_shader() {
            _shaders.emplace_back(_shader);
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
                Vector2 window_size = _parent_game->game_window->get_size();
                _projection_matrix = Matrix::create_orthographic_off_center(0, window_size.x, window_size.y, 0, -101, 101);
                glViewport(0, 0, window_size.x, window_size.y);
            }
#ifdef OPENGL
            if (target != nullptr)
                glBindFramebuffer(GL_FRAMEBUFFER, target->framebuffer);
            else
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
            _render_target = target;
        }
        
        void GraphicsDevice::set_view_matrix(Matrix view_matrix) {
            _view_matrix = view_matrix;
        }

        void GraphicsDevice::use_shader(Inferno::Graphics::Shader *shader) {
#ifdef OPENGL
            glUseProgram(shader->gl_program);
            _shader = shader;
#endif
        }
    }
}
