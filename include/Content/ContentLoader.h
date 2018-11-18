//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_CONTENTLOADER_H
#define INFERNO_CONTENTLOADER_H

#include "Inferno.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        struct Texture2D;
    }
    
    namespace Content {
        class INFERNO_API ContentLoader {
        public:
            static Graphics::Texture2D* load_texture(Graphics::GraphicsDevice* graphics_device, const char* filename);
        };
    }
}

#endif //INFERNO_CONTENTLOADER_H
