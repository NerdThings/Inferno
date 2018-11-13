#include "Content/ContentLoader.h"

#include "IL/il.h"

namespace Inferno {
    namespace Content {
        Texture2D ContentLoader::load_texture(GraphicsDevice* graphics_device, const char *filename) {
            /*CImg<int> image(filename);
            int width = image.width();
            int height = image.height();
            
            int size = width * height;
            Color data[size];
            
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    int i = x + y * width;
                    
                    int r = image(x, y, 0, 0);
                    int g = image(x, y, 0, 1);
                    int b = image(x, y, 0, 2);
                    int a = 1;
                    if (image.spectrum() == 4)
                        a = image(x, y, 0, 3);
                    
                    data[i] = Color(r, g, b, a);
                }
            }
            
            return Texture2D(graphics_device, width, height, data);*/
            
            ilLoadImage(filename);
            ILubyte *idata = ilGetData();
            
            int width = ilGetInteger(IL_IMAGE_WIDTH);
            int height = ilGetInteger(IL_IMAGE_HEIGHT);
            int channels = ilGetInteger(IL_IMAGE_CHANNELS);
    
            int size = width * height;
            std::vector<Color> data;
    
            for (int i = 0; i < width * height * channels; i+=channels) {
                int r = idata[i];
                int g = idata[i + 1];
                int b = idata[i + 2];
                int a = 255;
                if (channels == 4)
                    a = idata[i + 3];
                
                data.emplace_back(r, g, b, a);
            }
            
            return Texture2D(graphics_device, width, height, data);
        }
    }
}