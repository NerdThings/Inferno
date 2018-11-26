#include <utility>

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
    }
}