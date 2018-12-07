//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_RECTANGLE_H
#define INFERNO_RECTANGLE_H

#include "Inferno/Inferno.h"
#include "Inferno/Matrix.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"

namespace Inferno {
    /*
     * A rectangle
     */
    struct INFERNO_API Rectangle {
    private:
        //Methods
        
        /*
         * Create an internal matrix
         */
        Matrix get_matrix(bool invert = false);
    public:
        //Fields
        
        /*
         * Rectangle height
         */
        float height;
        
        /*
         * Rectangle rotation
         */
        float rotation;
        
        /*
         * Rectangle rotation origin
         */
        Vector2 rotation_origin;
        
        /*
         * Rectangle width
         */
        float width;
        
        /*
         * Rectangle X coordinate
         */
        float x;
        
        /*
         * Rectangle Y coordinate
         */
        float y;
        
        //Constructors
        
        /*
         * Create a new rectangle
         */
        Rectangle(float x, float y, float width, float height, float rotation = 0, Vector2 rotation_origin = Vector2());
        
        /*
         * Create a new rectangle
         */
        Rectangle(Vector2 position, Vector2 dimensions, float rotation = 0, Vector2 rotation_origin = Vector2());
        
        //Methods
        
        /*
         * Get the bottom left coordinate
         */
        Vector2 bottom_left();
        
        /*
         * Get the bottom right coordinate
         */
        Vector2 bottom_right();
        
        /*
         * Get the rectangle center
         */
        Vector2 center();
        
        /*
         * Test if the rectangle contains a point
         */
        bool contains(Vector2 point);
        
        /*
         * Test if a rectangle intersects another
         */
        bool intersects(Rectangle b);
        
        /*
         * Get the top left coordinate
         */
        Vector2 top_left();
        
        /*
         * Get the top right coordinate
         */
        Vector2 top_right();
        
        //Operators
        
        bool operator==(Rectangle b);
        bool operator!=(Rectangle b);
    };
}

#endif //INFERNO_RECTANGLE_H
