//
// Created by Reece Mackie on 13/12/18.
//

#ifndef INFERNO_LINE_H
#define INFERNO_LINE_H

#include "Inferno/Inferno.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    /*
     * Just a container for two Vector2 points
     */
    struct INFERNO_API Line {
        //Fields
        
        Vector2 p1;
        Vector2 p2;
        
        //Constructors
        
        Line();
        
        Line(Vector2 p1, Vector2 p2);
        
        //Methods
        
        /*
         * Get the gradient of the line
         */
        float gradient();
        
        bool intersects(Line b);
        
        //Operators
        
        bool operator==(Line b);
        bool operator!=(Line b);
    };
}

#endif //INFERNO_LINE_H
