//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_TEXTURE2D_H
#define INFERNO_TEXTURE2D_H

#include "Inferno/Inferno.h"

#include <vector>

#include "Color.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        
        /*
         * A Texture
         */
        struct INFERNO_API Texture2D {
        private:
            //Fields
            
            /*
             * Cached pixel data
             */
            std::vector<Color> _cached_data;
            
            /*
             * The texture width
             */
            int _width;
            
            /*
             * The texture height
             */
            int _height;
            
            //Methods
            
            /*
             * Create a texture (Native Code)
             */
            void create_texture(std::vector<Color> data);
        public:
            //Fields

#ifdef OPENGL
            /*
             * The texture ID
             */
            unsigned int id;
#endif
            
            //Constructors
            
            /*
             * Create a null texture
             */
            Texture2D();
            
            /*
             * Create a texture of a solid colour
             */
            Texture2D(int width, int height, Color color);
            
            /*
             * Create a texture using a colour array
             */
            Texture2D(int width, int height, std::vector<Color> data);
            
            //Deconstructors
            
            /*
             * Cleanup a Deleted Texture
             */
            ~Texture2D();
            
            //Methods
            
            /*
             * Retrieve the pixel data
             */
            std::vector<Color> get_data();
            
            /*
             * Get the texture height
             */
            int height();
            
            /*
             * Get the texture width
             */
            int width();
            
            /*
             * Set the image pixel data
             */
            void set_data(std::vector<Color> data);
        };
    }
}

#endif //INFERNO_TEXTURE2D_H
