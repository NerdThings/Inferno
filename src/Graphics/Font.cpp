#include <utility>

//
// Created by Reece Mackie on 22/11/18.
//

#include "Graphics/Font.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        Font::Font() {
        
        }
        
        Font::Font(std::vector<Glyph> glyphs) : glyphs(glyphs) {
        
        }
    }
}