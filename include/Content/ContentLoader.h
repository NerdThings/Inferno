//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_CONTENTLOADER_H
#define INFERNO_CONTENTLOADER_H

#include <string>

#include "Inferno.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        struct Font;
        struct Texture2D;
    }
    
    namespace Content {
        class INFERNO_API ContentLoader {
        public:
            static std::string get_working_directory();
            static Graphics::Font* load_font(Graphics::GraphicsDevice* graphics_device, std::string filename);
            static Graphics::Texture2D* load_texture(Graphics::GraphicsDevice* graphics_device, std::string filename);
        };
    }
}

#endif //INFERNO_CONTENTLOADER_H
