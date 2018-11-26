//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_CONTENTLOADER_H
#define INFERNO_CONTENTLOADER_H

#include <string>

#include "Inferno/Inferno.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        struct Font;
        struct Texture2D;
    }
    
    namespace Content {
        /*
         * Inferno Content Loader.
         */
        class INFERNO_API ContentLoader {
        public:
            /*
             * Get current working directory
             */
            static std::string get_working_directory();
            
            /*
             * Load a font from a file
             */
            static Graphics::Font load_font(std::string filename, int font_size);
            
            /*
             * Load a texture from a file
             */
            static Graphics::Texture2D* load_texture(std::string filename);
        };
    }
}

#endif //INFERNO_CONTENTLOADER_H
