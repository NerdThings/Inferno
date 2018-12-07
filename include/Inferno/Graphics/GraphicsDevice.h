//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_GRAPHICSDEVICE_H
#define INFERNO_GRAPHICSDEVICE_H

#include <string>
#include <vector>

#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/Shader.h"
#include "Inferno/Graphics/RenderTarget.h"
#include "Inferno/Graphics/Texture2D.h"
#include "Inferno/GameWindow.h"
#include "Inferno/Inferno.h"
#include "Inferno/Matrix.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"
#include "Inferno/Vector4.h"

namespace Inferno {
    class Game;
    
    namespace Graphics {
        /*
         * Game Graphics Device
         */
        class INFERNO_API GraphicsDevice {
            /*
             * The default shader (Inferno)
             */
            Shader* default_shader = nullptr;
            
            /*
             * The model matrices stack
             */
            std::vector<Matrix> _model_matrices;
            
            /*
             * The current model matrix
             */
            Matrix _model_matrix;
            
            /*
             * The graphics device parent game
             */
            Game* _parent_game = nullptr;
            
            /*
             * The current projection matrix
             */
            Matrix _projection_matrix;
            
            /*
             * The current render target
             */
            RenderTarget* _render_target = nullptr;
            
            /*
             * The render target stack
             */
            std::vector<RenderTarget*> _render_targets;
            
            /*
             * The current shader
             */
            Shader* _shader;
            
            /*
             * The shaders stack
             */
            std::vector<Shader*> _shaders;
            
            /*
             * The view matrices stack
             */
            std::vector<Matrix> _view_matrices;
            
            /*
             * The current view matrix
             */
            Matrix _view_matrix;
        public:
            //Constructors
        
            /*
             * Create a new Graphics Device
             */
            explicit GraphicsDevice(Game* game);
            
            //Deconstructors

            ~GraphicsDevice();
            
            //Methods
            
            /*
             * Clear the screen with a color
             */
            void clear(Color color);
            
            /*
             * Get the complete multiplied matrix
             */
            Matrix get_complete_matrix();
            
            /*
             * Get the current shader
             */
            Shader* get_current_shader();
            
            /*
             * Get the current render target
             */
            RenderTarget* get_current_target();
            
            /*
             * Get the current model matrix
             */
            Matrix get_model_matrix();
            
            /*
             * Get the current projection matrix
             */
            Matrix get_projection_matrix();
            
            /*
             * Get the current view matrix
             */
            Matrix get_view_matrix();
            
            /*
             * Pop a model matrix off the stack
             */
            void pop_model_matrix();
            
            /*
             * Push the current model matrix onto the stack
             */
            void push_model_matrix();
            
            /*
             * Pop a render target off the stack
             */
            void pop_render_target();
            
            /*
             * Push a render target onto the stack
             */
            void push_render_target();
            
            /*
             * Pop a shader off the stack
             */
            void pop_shader();
            
            /*
             * Push a shader onto the stack
             */
            void push_shader();
            
            /*
             * Pop a view matrix off the stack
             */
            void pop_view_matrix();
            
            /*
             * Push a view matrix onto the stack
             */
            void push_view_matrix();
            
            /*
             * Get the model matrix
             */
            void set_model_matrix(Matrix model_matrix);
            
            /*
             * Set the render target
             */
            void set_render_target(RenderTarget* target);
            
            /*
             * Set the view matrix
             */
            void set_view_matrix(Matrix view_matrix);
            
            /*
             * Set the current shader
             */
            void use_shader(Shader* shader);
        };
    }
}

#endif //INFERNO_GRAPHICSDEVICE_H
