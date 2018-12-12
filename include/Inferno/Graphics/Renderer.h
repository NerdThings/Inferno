//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_RENDERER_H
#define INFERNO_RENDERER_H

#include <string>
#include <vector>

#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/Font.h"
#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Graphics/RenderTarget.h"
#include "Inferno/Graphics/Shader.h"
#include "Inferno/Graphics/Texture2D.h"
#include "Inferno/Circle.h"
#include "Inferno/Inferno.h"
#include "Inferno/Matrix.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"

namespace Inferno {
    namespace Graphics {
        /*
         * Graphics Renderer
         */
        class INFERNO_API Renderer {
            //Fields
            
            /*
             * A blank texture used to satisfy shaders
             */
            Texture2D* _blank_texture = nullptr;
#ifdef OPENGL
            /*
             * The current vertex array
             */
            unsigned int _vertex_array;
#endif
            /*
             * The game graphics device
             */
            GraphicsDevice* _graphics_device;
            
            //Methods
            
            /*
             * Add a set of data to a float buffer
             */
            void add_to_buffer(Vector3 position, Vector2 texcoord, Color color, std::vector<float>* data);
            
            /*
             * Create a model matrix
             */
            Matrix create_model_matrix(Vector2 origin = Vector2(), float rotation = 0, float scale = 1);
            
            /*
             * Send the matrix to the shader
             */
            void set_matrix(Vector2 origin = Vector2(), float rotation = 0, float scale = 1);

#ifdef OPENGL
            
            void gl_draw_buffer(int drawmode, std::vector<float> data);
            
#endif
            
        public:
            //Constructors
        
            /*
             * Create a new renderer
             */
            explicit Renderer(GraphicsDevice* graphics_device);
            
            //Deconstructors
            
            /*
             * Handles destroying renderer resources
             */
            ~Renderer();
            
            //Methods
            
            /*
             * Draw a circle.
             * OBSOLETE: Will be removed after the colliders-revamp branch is merged
             */
            void draw_circle(Vector2 position, float radius, Color color = Color::white, float depth = 0, float rotation = 0, bool filled = true, int line_width = 1, int circle_precision = 24, Vector2 origin = Vector2());
    
            /*
             * Draw a circle
             */
            void draw_circle(Circle circle, Color color = Color::white, float depth = 0, float rotation = 0, bool filled = true, int line_width = 1, int circle_precision = 24, Vector2 origin = Vector2());
            
            /*
             * Draw a line
             */
            void draw_line(Vector2 pos_a, Vector2 pos_b, Color color = Color::white, int line_width = 1, float depth = 0, float rotation = 0, Vector2 origin = Vector2());
            
            /*
             * Draw some lines
             */
            void draw_lines(std::vector<Vector2> points, Color color = Color::white, int line_width = 1, float depth = 0, float rotation = 0, Vector2 origin = Vector2());
            
            /*
             * Draw a rectangle
             */
            void draw_rectangle(Rectangle rect, Color color, bool filled = true, int line_width = 1, float depth = 0, float rotation = 0, Vector2 origin = Vector2());
            
            /*
             * Draw a render target
             */
            void draw_render_target(RenderTarget* target, Vector2 pos, Rectangle* source_rectangle = nullptr, float depth = 0, float rotation = 0, Color color = Color::white);
            
            /*
             * Draw a render target
             */
            void draw_render_target(RenderTarget* target, Rectangle destination_rectangle, Rectangle* source_rectangle = nullptr, float depth = 0, float rotation = 0, Color color = Color::white);
            
            /*
             * Draw some text
             */
            void draw_text(std::string text, Vector2 position, Font font, Color color = Color::white, float depth = 0, float rotation = 0);
            
            /*
             * Draw a texture
             */
            void draw_texture(Texture2D* texture, Vector2 position, Rectangle* source_rectangle = nullptr, float depth = 0, float rotation = 0, Color color = Color::white, Vector2 origin = Vector2::zero);
            
            /*
             * Draw a texture
             */
            void draw_texture(Texture2D* texture, Rectangle destination_rectangle, Rectangle* source_rectangle = nullptr, float depth = 0, float rotation = 0, Color color = Color::white, Vector2 origin = Vector2::zero);
        };
    }
}

#endif //INFERNO_RENDERER_H
