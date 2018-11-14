//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_TEXTURE2D_H
#define INFERNO_TEXTURE2D_H

#include "Inferno.h"

#include <vector>

#include "Graphics/Color.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        
        struct INFERNO_API Texture2D {
        private:
            //Fields
            
            std::vector<Color> _cached_data;
            GraphicsDevice* _graphics_device;
            int _width;
            int _height;
            
            //Methods
            
            void create_texture(std::vector<Color> data);
        public:
            //Fields

#ifdef OPENGL
            unsigned int id;
#endif
            
            //Constructors
            
            Texture2D();
            Texture2D(GraphicsDevice* graphics_device, int width, int height, Color color);
            Texture2D(GraphicsDevice* graphics_device, int width, int height, std::vector<Color> data);
            
            //Deconstructors
            
            ~Texture2D();
            
            //Methods
            
            std::vector<Color> get_data();
            int get_height();
            int get_width();
            void set_data(std::vector<Color> data);
            
            //Operators
            
            void operator=(Texture2D texture);
        };
    }
}

#endif //INFERNO_TEXTURE2D_H
