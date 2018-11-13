#ifndef Inferno_Content_ContentLoader
#define Inferno_Content_ContentLoader

#include "Inferno.h"

#include "Graphics/GraphicsDevice.h"
#include "Graphics/Texture2D.h"

namespace Inferno {
    
    using namespace Graphics;
    
    namespace Content {
        class INFERNO_API ContentLoader {
        public:
            static Texture2D load_texture(GraphicsDevice* graphics_device, const char* filename);
        };
    }
}

#endif
