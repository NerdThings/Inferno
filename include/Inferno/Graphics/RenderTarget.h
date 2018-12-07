//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_RENDERTARGET_H
#define INFERNO_RENDERTARGET_H

#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Inferno.h"

namespace Inferno {
    namespace Graphics {
        /*
         * A render target
         */
        struct INFERNO_API RenderTarget {
        public:
            //Fields
            
            /*
             * Render target width
             */
            const int width;
            
            /*
             * Render target height
             */
            const int height;

#ifdef OPENGL
            /*
             * The frame buffer
             */
            unsigned int framebuffer = 0;
            
            /*
             * The final rendered texture
             */
            unsigned int rendered_texture = 0;
            
            /*
             * The depth render buffer
             */
            unsigned int depth_render_buffer = 0;
#endif
            
            //Constructors
            
            /*
             * Create a new render target
             */
            RenderTarget(int width, int height);
            
            //Deconstructors
            
            /*
             * Cleanup render target
             */
            ~RenderTarget();
        };
    }
}

#endif //INFERNO_RENDERTARGET_H
