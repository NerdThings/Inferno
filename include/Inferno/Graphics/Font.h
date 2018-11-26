//
// Created by Reece Mackie on 22/11/18.
//

#ifndef INFERNO_FONT_H
#define INFERNO_FONT_H

#include "Inferno/Inferno.h"

#include <vector>

#include "Glyph.h"
#include "Texture2D.h"
#include "Inferno/Vector4.h"

namespace Inferno {
    namespace Graphics {
        struct INFERNO_API Font {
            //Fields
            
            std::vector<Glyph> glyphs;
            
            //Constructors
            
            Font();
    
            explicit Font(std::vector<Glyph> glyphs);
        };
    }
}

#endif //INFERNO_FONT_H
