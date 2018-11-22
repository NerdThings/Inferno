//
// Created by Reece Mackie on 22/11/18.
//

#ifndef INFERNO_FONT_H
#define INFERNO_FONT_H

#include "Inferno.h"

#include <vector>

#include "Graphics/Glyph.h"
#include "Graphics/Texture2D.h"
#include "Vector4.h"

namespace Inferno {
    namespace Graphics {
        struct INFERNO_API Font {
            //Fields
            
            std::vector<Glyph> glyphs;
            
            //Constructors
            
            Font();
        };
    }
}

#endif //INFERNO_FONT_H
