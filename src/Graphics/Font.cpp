//
// Created by Reece Mackie on 22/11/18.
//

#include "Inferno/Graphics/Font.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        Font::Font() = default;
        
        Font::Font(std::vector<Glyph> glyphs) : glyphs(std::move(glyphs)) {
        
        }
    
        Vector2 Font::measure_string(std::string string) {
            Vector2 size = Vector2(0, 0);
            
            float currentWidth = 0;
            
            //Default height
            size.y = glyphs['A'].size.y + glyphs['A'].bearing.y;
            
            for (char c : string) {
                if (c == '\n') {
                    size.y += glyphs[space_char].size.y + glyphs['A'].bearing.y;
                    size.x += currentWidth;
                    currentWidth = 0;
                    continue;
                }
                if (c == ' ') {
                    currentWidth += glyphs[space_char].size.x;
                    continue;
                }
    
                currentWidth += glyphs[c].size.x;
            }
            
            if (currentWidth > size.x)
                size.x = currentWidth;
            
            return size;
        }
    }
}
