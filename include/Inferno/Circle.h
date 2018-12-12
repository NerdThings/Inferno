//
// Created by Reece Mackie on 12/12/18.
//

#ifndef INFERNO_CIRCLE_H
#define INFERNO_CIRCLE_H

#include "Inferno/Inferno.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    struct Rectangle;
    
    /*
     * A circle struct
     */
    struct INFERNO_API Circle {
        //Fields
    
        /*
         * The centre of the circle
         */
        Vector2 centre;
        
        /*
         * The radius of the circle
         */
        float radius;
        
        //Constructors
        
        Circle();
        Circle(Vector2 centre, float radius);
        
        //Methods
        
        /*
         * Test if a point is contained within a circle
         */
        bool contains(Vector2 point);
        
        /*
         * Test if a circle is intersecting with this circle
         */
        bool intersects(Circle b);
        
        /*
         * Test if a rectangle is intersecting this circle
         */
        bool intersects(Rectangle b);
        
        //Operators
        
        bool operator==(Circle b);
        bool operator!=(Circle b);
    };
}

#endif //INFERNO_CIRCLE_H
