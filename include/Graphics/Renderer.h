//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_RENDERER_H
#define INFERNO_RENDERER_H

#include "Inferno.h"

#include <vector>

namespace Inferno {
    struct Rectangle;
    struct Matrix;
    struct Vector2;
    struct Vector3;
    
    namespace Graphics {
        struct Color;
        class GraphicsDevice;
        struct RenderTarget;
        struct Texture2D;
        
        class INFERNO_API Renderer {
            //Fields
            
            Texture2D* _blank_texture = nullptr;
#ifdef OPENGL
            unsigned int _vertex_array;
#endif
            GraphicsDevice* _graphics_device;
            
            //Methods
            
            void add_to_buffer(Vector3 position, Vector2 texcoord, Color color, std::vector<float>* data);
            void set_matrix(Vector2 translation);

#ifdef OPENGL
            
            void gl_draw_buffer(int drawmode, std::vector<float> data);
            
#endif
            
        public:
            //Constructors
        
            explicit Renderer(GraphicsDevice* graphics_device);
            
            //Deconstructors
            
            ~Renderer();
            
            //Methods
            
            void draw_circle(Vector2 position, float radius, Color color, float depth, bool filled, int line_width, int circle_precision);
            void draw_line(Vector2 pos_a, Vector2 pos_b, Color color, int line_width, float depth);
            void draw_lines(std::vector<Vector2> points, Color color, int line_width, float depth);
            void draw_rectangle(Rectangle rect, Color color, float depth, bool filled, int line_width);
            void draw_render_target(RenderTarget* target, Vector2 pos, Rectangle* source_rectangle, float depth, Color color);
            void draw_render_target(RenderTarget* target, Rectangle destination_rectangle, Rectangle* source_rectangle, float depth, Color color);
            //void draw_text(std::string text, Vector2 position, Font font, Color color, float depth, Vector2 origin);
            void draw_texture(Texture2D* texture, Vector2 position, Rectangle* source_rectangle, float depth, Color color, Vector2 origin);
            void draw_texture(Texture2D* texture, Rectangle destination_rectangle, Rectangle* source_rectangle, float depth, Color color, Vector2 origin);
        };
    }
}

#endif //INFERNO_RENDERER_H
