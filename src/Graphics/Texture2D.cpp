//
// Created by Reece Mackie on 14/11/18.
//

#if OPENGL
#include "glad/glad.h"
#endif

#if SDL
#include "SDL_opengl.h"
#endif

#include "Graphics/Texture2D.h"

namespace Inferno {
    namespace Graphics {
        //Private methods
        
        void Texture2D::create_texture(std::vector<Color> data){
#ifdef OPENGL
            //OPENGL CREATE TEXTURE
            
            //Set texture unit
            glActiveTexture(GL_TEXTURE0);
    
            //Cache data
            _cached_data = data;
    
            //Create texture
            glGenTextures(1, &id);
    
            //Convert data
            auto * gl_data = new unsigned int[_width * _height];
    
            //The following code will not modify the data to OpenGL's format because we don't use standard pixel coordinates
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
            
            //Generate mipmap
            glGenerateMipmap(GL_TEXTURE_2D);
    
            //Unbind texture
            glBindTexture(GL_TEXTURE_2D, 0);
            
            //Delete temp data
            delete[] gl_data;
#endif
        }
        
        //Constructors
        
        Texture2D::Texture2D() {
            //Set blanks
            _width = 0;
            _height = 0;
        }
        
        Texture2D::Texture2D(GraphicsDevice *graphics_device, int width, int height, Color color) : _graphics_device(graphics_device), _width(width), _height(height) {
            //Create vector
            std::vector<Color> colordata;
            for (int i = 0; i < width * height; i++) {
                colordata.emplace_back(color);
            }
            
            //Create texture
            create_texture(colordata);
        }
        
        Texture2D::Texture2D(GraphicsDevice *graphics_device, int width, int height, std::vector<Color> data) : _graphics_device(graphics_device), _width(width), _height(height) {
            //Create texture
            create_texture(data);
        }
        
        //Deconstructors
        
        Texture2D::~Texture2D() {
            //TODO
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
            //TODO:
            throw "Not implemented.";
        }
        
        //Operators
        
        void Texture2D::operator=(Texture2D texture) {
            //TODO
        }
    }
}
