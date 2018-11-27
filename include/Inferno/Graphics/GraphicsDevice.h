//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_GRAPHICSDEVICE_H
#define INFERNO_GRAPHICSDEVICE_H

#include "Inferno/Inferno.h"

#include <string>
#include <vector>

#include "Inferno/Point.h"
#include "Inferno/Matrix.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"
#include "Inferno/Vector4.h"

namespace Inferno {
    class Game;
    
    namespace Graphics {
        struct Color;
        struct Shader;
        struct RenderTarget;
        struct Texture2D;
        
        class INFERNO_API GraphicsDevice {
            Shader* _current_fragment_shader = nullptr;
            Shader* _current_vertex_shader = nullptr;
            Shader* _default_fragment_shader = nullptr;
            Shader* _default_vertex_shader = nullptr;
#ifdef OPENGL
            unsigned int _gl_program;
#endif
            std::vector<Matrix> _model_matrices;
            Matrix _model_matrix;
            Game* _parent_game = nullptr;
            Matrix _projection_matrix;
            RenderTarget* _render_target = nullptr;
            std::vector<RenderTarget*> _render_targets;
            std::vector<Matrix> _view_matrices;
            Matrix _view_matrix;
        public:
            //Constructors
        
            explicit GraphicsDevice(Game* game);
            
            //Deconstructors

            ~GraphicsDevice();
            
            //Methods
            
            void attach_shader(Shader* shader);
            void clear(Color color);
            
            Matrix get_complete_matrix();
            RenderTarget* get_current_target(); //TEMP
            Matrix get_model_matrix();
            Matrix get_projection_matrix();
            Matrix get_view_matrix();
            void pop_model_matrix();
            void push_model_matrix();
            void pop_render_target();
            void push_render_target();
            void pop_view_matrix();
            void push_view_matrix();
            void set_model_matrix(Matrix model_matrix);
            void set_render_target(RenderTarget* target);
            void set_view_matrix(Matrix view_matrix);
            
            //TEMP:
            int shader_get_attrib(std::string attrib);
            int shader_get_uniform(std::string uniform);
            void shader_uniform_set(std::string uniform, float value);
            void shader_uniform_set(std::string uniform, int value);
            void shader_uniform_set(std::string uniform, Vector2 value);
            void shader_uniform_set(std::string uniform, Point value);
            void shader_uniform_set(std::string uniform, float value1, float value2);
            void shader_uniform_set(std::string uniform, int value1, int value2);
            void shader_uniform_set(std::string uniform, Vector3 value);
            void shader_uniform_set(std::string uniform, Color value);
            void shader_uniform_set(std::string uniform, float value1, float value2, float value3);
            void shader_uniform_set(std::string uniform, int value1, int value2, int value3);
            void shader_uniform_set(std::string uniform, Vector4 value);
            void shader_uniform_set(std::string uniform, float value1, float value2, float value3, float value4);
            void shader_uniform_set(std::string uniform, int value1, int value2, int value3, int value4);
            void shader_uniform_set(std::string uniform, Matrix value);
        };
    }
}

#endif //INFERNO_GRAPHICSDEVICE_H
