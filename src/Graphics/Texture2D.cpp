#include "Graphics/Texture2D.h"

#if OPENGL
#include "glad/glad.h"
#endif

#if SDL
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {
        //Private Methods
        void Texture2D::create_texture(Color *data) {
#ifdef OPENGL
            //Set texture unit
            glActiveTexture(GL_TEXTURE0);
            
            //Cache data
            _cached_data = data;
            
            //Create texture
            glGenTextures(1, &_id);
            
            //Convert data
            unsigned int* gl_data = new unsigned int[width * height];
    
            //TODO: Flip to make work...
            for (int i = 0; i < width * height; i++) {
                gl_data[i] = data[i].packed_value;
            }
            
            //Bind texture
            glBindTexture(GL_TEXTURE_2D, _id);
            
            //Set data
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, gl_data);
            
            //Set parameters
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            
            //Unbind texture
            glBindTexture(GL_TEXTURE_2D, 0);
#endif
        }
        
        //Constructors
        
        Texture2D::Texture2D(GraphicsDevice* graphics_device, int width, int height, Color *data) : _graphics_device(graphics_device) {
            //Set dimensions
            this->width = width;
            this->height = height;
            
            //Create texture
            create_texture(data);
        }
        
        //Methods
        
        Color* Texture2D::get_data() {
            return _cached_data;
        }
        
        void Texture2D::set_data(Color *data) {
            //TODO: DESTROY TEXTURE!!
            
            create_texture(data);
        }
    }
}