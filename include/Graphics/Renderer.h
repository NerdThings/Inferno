//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_RENDERER_H
#define INFERNO_RENDERER_H

#include "Inferno.h"

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
            
        public:
            //Constructors
        
            explicit Renderer(GraphicsDevice* graphics_device);
            
            //Deconstructors
            
            ~Renderer();
            
            //Methods
            
            void draw_rectangle(Rectangle rect, Color color, float depth = 0);
            
            void draw_rendertarget(RenderTarget target, Vector2 position, Color color, float depth = 0);
            
            void draw_rendertarget(RenderTarget target, Rectangle destination_rectangle, Color color, float depth = 0);
            
            void draw_texture(Texture2D texture, Vector2 position, Color color, float depth = 0);
            
            void draw_texture(Texture2D texture, Rectangle destination_rectangle, Color color, float depth = 0);
        };
    }
}

#endif //INFERNO_RENDERER_H
