//
// Created by Reece Mackie on 15/11/18.
//

#include <filesystem>

#include "IL/il.h"

#include "Content/ContentLoader.h"
#include "Graphics/Color.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/Texture2D.h"

namespace Inferno {
    namespace Content {
        const char* ContentLoader::get_working_directory() {
            return std::filesystem::current_path().c_str();
        }
        
        Graphics::Texture2D* ContentLoader::load_texture(Graphics::GraphicsDevice* graphics_device, const char *filename) {
            ilLoadImage(filename);
            ILubyte *idata = ilGetData();
    
            int width = ilGetInteger(IL_IMAGE_WIDTH);
            int height = ilGetInteger(IL_IMAGE_HEIGHT);
            int channels = ilGetInteger(IL_IMAGE_CHANNELS);
    
            int size = width * height;
            std::vector<Graphics::Color> data;
    
            for (int i = 0; i < width * height * channels; i+=channels) {
                int r = idata[i];
                int g = idata[i + 1];
                int b = idata[i + 2];
                int a = 255;
                if (channels == 4)
                    a = idata[i + 3];
        
                data.emplace_back(r, g, b, a);
            }
    
            return new Graphics::Texture2D(graphics_device, width, height, data);
        }
    }
}