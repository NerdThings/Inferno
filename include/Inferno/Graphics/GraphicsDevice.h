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
            Shader* default_shader = nullptr;
            std::vector<Matrix> _model_matrices;
            Matrix _model_matrix;
            Game* _parent_game = nullptr;
            Matrix _projection_matrix;
            RenderTarget* _render_target = nullptr;
            std::vector<RenderTarget*> _render_targets;
            Shader* _shader;
            std::vector<Shader*> _shaders;
            std::vector<Matrix> _view_matrices;
            Matrix _view_matrix;
        public:
            //Constructors
        
            explicit GraphicsDevice(Game* game);
            
            //Deconstructors

            ~GraphicsDevice();
            
            //Methods
            
            void clear(Color color);
            Matrix get_complete_matrix();
            Shader* get_current_shader();
            RenderTarget* get_current_target();
            Matrix get_model_matrix();
            Matrix get_projection_matrix();
            Matrix get_view_matrix();
            void pop_model_matrix();
            void push_model_matrix();
            void pop_render_target();
            void push_render_target();
            void pop_shader();
            void push_shader();
            void pop_view_matrix();
            void push_view_matrix();
            void set_model_matrix(Matrix model_matrix);
            void set_render_target(RenderTarget* target);
            void set_view_matrix(Matrix view_matrix);
            void use_shader(Shader* shader);
        };
    }
}

#endif //INFERNO_GRAPHICSDEVICE_H
