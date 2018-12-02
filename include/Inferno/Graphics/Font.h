//
// Created by Reece Mackie on 22/11/18.
//

#ifndef INFERNO_FONT_H
#define INFERNO_FONT_H

#include "Inferno/Inferno.h"

#include <string>
#include <vector>

#include "Inferno/Graphics/Glyph.h"
#include "Inferno/Graphics/Texture2D.h"
#include "Inferno/Vector4.h"

namespace Inferno {
    namespace Graphics {
        struct INFERNO_API Font {
            //Fields
            
            std::vector<Glyph> glyphs;
            
            //Constructors
            
            Font();
    
            explicit Font(std::vector<Glyph> glyphs);
            
            //Methods
    
            Vector2 measure_string(std::string string);
        };
    }
}

#endif //INFERNO_FONT_H
