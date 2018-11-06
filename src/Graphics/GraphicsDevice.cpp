#include "Graphics/GraphicsDevice.h"
#include "Graphics/RenderTarget.h"

#ifdef SDL
#include "glad/glad.h"
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {

        GraphicsDevice::GraphicsDevice(GameWindow *window) : _paired_window(window) {
        }

        void GraphicsDevice::delete_render_target(RenderTarget *target) {
            _targets_to_dispose.push_back(target);
        }

        void GraphicsDevice::end_draw() {
            for (RenderTarget *target : _targets_to_dispose) {
#ifdef OPENGL

                //Unbinds
                glBindRenderbuffer(GL_RENDERBUFFER, 0);
                glBindTexture(GL_TEXTURE_2D, 0);
                glBindFramebuffer(GL_FRAMEBUFFER, 0);

                //Delete target
                glDeleteRenderbuffers(1, &target->depth_render_buffer);
                glDeleteTextures(1, &target->rendered_texture);
                glDeleteFramebuffers(1, &target->framebuffer);

#endif

                //Set all to 0
                target->depth_render_buffer = 0;
                target->rendered_texture = 0;
                target->framebuffer = 0;
            }
        }

        RenderTarget *GraphicsDevice::get_render_target() const {
            return _render_target;
        }

        void GraphicsDevice::set_render_target(RenderTarget *target) {
#ifdef OPENGL

            //Grab id
            unsigned int id = 0;
            if (target != nullptr)
                id = target->framebuffer;

            //Bind buffer
            glBindFramebuffer(GL_FRAMEBUFFER, id);

#endif

            //Set field
            _render_target = target;
        }
    }
}