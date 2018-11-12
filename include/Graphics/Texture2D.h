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
            
            Color* _cached_data;
            
            GraphicsDevice* _graphics_device;
            
            //Methods
            
            void create_texture(Color* data);
            
        public:
            //Fields

#ifdef OPENGL
            unsigned int id;
#endif
        
            int width;
            
            int height;
            
            //Constructors
            
            Texture2D(GraphicsDevice* graphics_device, int width, int height, Color* data);
            
            //Deconstructors
            
            ~Texture2D();
            
            //Methods
            
            Color* get_data();
            
            void set_data(Color* data);
        };
    }
}

#endif