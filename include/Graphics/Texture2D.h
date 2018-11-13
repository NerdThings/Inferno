#ifndef Inferno_Graphics_Texture2D
#define Inferno_Graphics_Texture2D

#include "Inferno.h"

#include "Graphics/Color.h"
#include "Graphics/GraphicsDevice.h"

namespace Inferno {
    namespace Graphics {
        struct Texture2D {
        private:
            //Fields
            
            std::vector<Color> _cached_data;
            
            GraphicsDevice* _graphics_device;
    
            int _height;
    
            int _width;
            
            //Methods
            
            void create_texture(std::vector<Color> data);
            
        public:
            //Fields

#ifdef OPENGL
            unsigned int id;
#endif
        
            
            
            //Constructors
            
            Texture2D();
            
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

#endif