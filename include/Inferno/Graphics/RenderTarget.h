//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_RENDERTARGET_H
#define INFERNO_RENDERTARGET_H

#include "Inferno/Inferno.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        
        struct INFERNO_API RenderTarget {
        public:
            //Fields
            
            const int width;
            const int height;

#ifdef OPENGL
            unsigned int framebuffer = 0;
            unsigned int rendered_texture = 0;
            unsigned int depth_render_buffer = 0;
#endif
            
            //Constructors
            
            RenderTarget(int width, int height);
            
            //Deconstructors
            
            ~RenderTarget();
        };
    }
}

#endif //INFERNO_RENDERTARGET_H
