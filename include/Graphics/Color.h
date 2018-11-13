//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_COLOR_H
#define INFERNO_COLOR_H

#include "Inferno.h"

namespace Inferno {
    namespace Graphics {
        struct INFERNO_API Color {
            //Fields
            
            unsigned int packed_value;
            
            //Constructors
            
            Color();
            explicit Color(unsigned int packed_value);
            Color(float r, float g, float b, float a);
            Color(int r, int g, int b, int a);
            
            //Methods
            
            float get_r();
            float get_g();
            float get_b();
            float get_a();
            
            //Operators
            
            bool operator==(Color b);
            bool operator!=(Color b);
        };
    }
}

#endif //INFERNO_COLOR_H
