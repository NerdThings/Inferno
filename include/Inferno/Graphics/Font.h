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
        /*
         * A text font
         */
        struct INFERNO_API Font {
            //Fields
            
            /*
             * Font Glyphs
             */
            std::vector<Glyph> glyphs;
            
            /*
             * The character whose dimensions get used when a space or newline is encountered
             */
            char space_char = 'I';
            
            //Constructors
            
            /*
             * An empty font
             */
            Font();
    
            /*
             * Create a new font from existing glyphs
             */
            explicit Font(std::vector<Glyph> glyphs);
            
            //Methods
    
            /*
             * Measure the size of a string in this font
             */
            Vector2 measure_string(std::string string);
        };
    }
}

#endif //INFERNO_FONT_H
