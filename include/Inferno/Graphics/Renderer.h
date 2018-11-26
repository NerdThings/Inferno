//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_RENDERER_H
#define INFERNO_RENDERER_H

#include "Inferno/Graphics/Color.h"
#include "Inferno/Inferno.h"
#include "Inferno/Vector2.h"

#include <string>
#include <vector>

namespace Inferno {
    struct Rectangle;
    struct Matrix;
    struct Vector3;
    
    namespace Graphics {
        struct Font;
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
            void set_matrix(Vector2 origin = Vector2(), float rotation = 0, float scale = 1);

#ifdef OPENGL
            
            void gl_draw_buffer(int drawmode, std::vector<float> data);
            
#endif
            
        public:
            //Constructors
        
            explicit Renderer(GraphicsDevice* graphics_device);
            
            //Deconstructors
            
            ~Renderer();
            
            //Methods
            
            void draw_circle(Vector2 position, float radius, Color color = Color::white, float depth = 0, float rotation = 0, bool filled = true, int line_width = 1, int circle_precision = 24);
            void draw_line(Vector2 pos_a, Vector2 pos_b, Color color = Color::white, int line_width = 1, float depth = 0, float rotation = 0, Vector2 origin = Vector2());
            void draw_lines(std::vector<Vector2> points, Color color = Color::white, int line_width = 1, float depth = 0, float rotation = 0, Vector2 origin = Vector2());
            void draw_rectangle(Rectangle rect, Color color, bool filled = true, int line_width = 1, float depth = 0, float rotation = 0, Vector2 origin = Vector2());
            void draw_render_target(RenderTarget* target, Vector2 pos, Rectangle* source_rectangle = nullptr, float depth = 0, float rotation = 0, Color color = Color::white);
            void draw_render_target(RenderTarget* target, Rectangle destination_rectangle, Rectangle* source_rectangle = nullptr, float depth = 0, float rotation = 0, Color color = Color::white);
            void draw_text(std::string text, Vector2 position, Font font, Color color = Color::white, float depth = 0, float rotation = 0);
            void draw_texture(Texture2D* texture, Vector2 position, Rectangle* source_rectangle = nullptr, float depth = 0, float rotation = 0, Color color = Color::white, Vector2 origin = Vector2::zero);
            void draw_texture(Texture2D* texture, Rectangle destination_rectangle, Rectangle* source_rectangle = nullptr, float depth = 0, float rotation = 0, Color color = Color::white, Vector2 origin = Vector2::zero);
        };
    }
}

#endif //INFERNO_RENDERER_H
