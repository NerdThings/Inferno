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
        /*
         * A text glyph
         */
        struct INFERNO_API Glyph {
            /*
             * Glyph texture
             */
            Texture2D* texture;
            
            /*
             * Glyph size
             */
            Vector2 size;
            
            /*
             * Glyph bearing
             */
            Vector2 bearing;
            
            /*
             * Glyph advance
             */
            unsigned int advance;
        };
    }
}

#endif //INFERNO_GLYPH_H
