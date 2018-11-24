//
// Created by Reece Mackie on 15/11/18.
//

#include "IL/il.h"

#include <cstring>
#include <filesystem>
#include <fstream>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <iostream>
#include <map>

#include "Content/ContentLoader.h"
#include "Graphics/Color.h"
#include "Graphics/Font.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/Texture2D.h"

namespace Inferno {
    namespace Content {
        std::string ContentLoader::get_working_directory() {
            std::filesystem::path cwd = std::filesystem::current_path();
            return cwd.string();
        }
        
        Graphics::Font ContentLoader::load_font(std::string filename, int font_size) {
            FT_Library ft;
            if (FT_Init_FreeType(&ft))
                throw "Could not init FreeType Library";
    
            FT_Face face;
            if (FT_New_Face(ft, filename.c_str(), 0, &face))
                throw "Failed to load font";
    
            FT_Set_Pixel_Sizes(face, 0, font_size);
            
            std::vector<Graphics::Glyph> glyphs;
    
            for (int c = 0; c < 128; c++) {
                int s = FT_Load_Char(face, c, FT_LOAD_RENDER);
                if (s) {
                    throw "Unable to load char";
                }
                
                //Create texture
                
                unsigned char* data = face->glyph->bitmap.buffer;
                int width = face->glyph->bitmap.width;
                int height = face->glyph->bitmap.rows;
                int count = width * height;
                
                std::vector<Graphics::Color> colordata;
                for (int i = 0; i < count; i++) {
                    colordata.emplace_back(Graphics::Color(255, 255, 255, data[i]));
                }
                
                Graphics::Texture2D* glyphtex = new Graphics::Texture2D(width, height, colordata);
                Graphics::Glyph g;
                g.texture = glyphtex;
                g.size = Vector2(width, height);
                g.bearing = Vector2(face->glyph->bitmap_left, face->glyph->bitmap_top);
                g.advance = (unsigned int)face->glyph->advance.x;
                glyphs.push_back(g);
            }
            
            FT_Done_Face(face);
            FT_Done_FreeType(ft);

            return Graphics::Font(glyphs);
        }
        
        Graphics::Texture2D* ContentLoader::load_texture(std::string filename) {
            ilLoadImage(filename.c_str());
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
    
            return new Graphics::Texture2D(width, height, data);
        }
    }
}