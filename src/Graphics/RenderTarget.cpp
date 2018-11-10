#include "Graphics/RenderTarget.h"

#ifdef SDL
#include "glad/glad.h"
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {
        RenderTarget::RenderTarget(int _width, int _height) : width(_width), height(_height) {
#ifdef SDL

            //Create the framebuffer
            glGenFramebuffers(1, &framebuffer);

            //Bind framebuffer
            glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

            //Create the texture we will render to
            glGenTextures(0, &rendered_texture);

            //Bind the texture
            glBindTexture(GL_TEXTURE_2D, rendered_texture);

            //Set to empty image
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

            //Set filtering
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

            //Depth buffer
            glGenRenderbuffers(0, &depth_render_buffer);

            //Bind buffer
            glBindRenderbuffer(GL_RENDERBUFFER, depth_render_buffer);

            //Set buffer storage
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);

            //Add to framebuffer
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depth_render_buffer);

            //Set the texture as colour attachment 0
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, rendered_texture, 0);

            //Set draw buffer
            //glDrawBuffer(GL_COLOR_ATTACHMENT0);

            //Check the buffer is ok
            if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
                throw "Framebuffer is not complete.";

            //Unbinds
            glBindRenderbuffer(GL_RENDERBUFFER, 0);
            glBindTexture(GL_TEXTURE_2D, 0);
            glBindFramebuffer(GL_FRAMEBUFFER, 0);

#endif
        }
    }
}