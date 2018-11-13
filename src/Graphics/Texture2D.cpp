#include <cstdio>
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
        
        void Texture2D::create_texture(std::vector<Color> data) {
#ifdef OPENGL
            //Set texture unit
            glActiveTexture(GL_TEXTURE0);
            
            //Cache data
            _cached_data = data;
            
            //Create texture
            glGenTextures(1, &id);
            
            //Convert data
            unsigned int gl_data[_width * _height];
    
            //TODO: Flip to make work...
            for (int i = 0; i < _width * _height; i++) {
                gl_data[i] = data[i].packed_value;
            }
            
            //Bind texture
            glBindTexture(GL_TEXTURE_2D, id);
            
            //Set data
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, gl_data);
            
            //Set parameters
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            
            //Unbind texture
            glBindTexture(GL_TEXTURE_2D, 0);
#endif
        }
        
        //Constructors
        
        Texture2D::Texture2D() : _graphics_device(nullptr), _width(0), _height(0) {
            //Do nothing, null
        }
        
        Texture2D::Texture2D(GraphicsDevice* graphics_device, int width, int height, std::vector<Color> data) : _graphics_device(graphics_device), _width(width), _height(height) {
            //If this is null, we ditch.
            //TODO: Default constructor to allow null
            if (graphics_device == nullptr)
                return;
            
            //Create texture
            create_texture(data);
        }
        
        //Deconstructors
        
        Texture2D::~Texture2D() {
            //TODO: DESTROY TEXTURE!!
        }
        
        //Methods
    
        std::vector<Color> Texture2D::get_data() {
            return _cached_data;
        }
        
        int Texture2D::get_height() {
            return _height;
        }
        
        int Texture2D::get_width() {
            return _width;
        }
        
        void Texture2D::set_data(std::vector<Color> data) {
            //TODO: DESTROY TEXTURE!!
            
            create_texture(data);
        }
        
        //Operators
        
        void Texture2D::operator=(Graphics::Texture2D texture) {
            //TODO: Destroy current texture
            
            //Update fields
            id = texture.id;
            _width = texture._width;
            _height = texture._height;
            _cached_data = texture._cached_data;
            _graphics_device = texture._graphics_device;
        }
    }
}