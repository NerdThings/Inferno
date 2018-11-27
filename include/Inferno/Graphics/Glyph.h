//
// Created by Reece Mackie on 22/11/18.
//

#ifndef INFERNO_GLYPH_H
#define INFERNO_GLYPH_H

#include "Inferno/Inferno.h"

#include "Texture2D.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    namespace Graphics {
        struct INFERNO_API Glyph {
            Texture2D* texture;
            Vector2 size;
            Vector2 bearing;
            unsigned int advance;
        };
    }
}

#endif //INFERNO_GLYPH_H