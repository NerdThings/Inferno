//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_VECTOR2_H
#define INFERNO_VECTOR2_H

#include "Inferno/Inferno.h"

namespace Inferno {
    struct Matrix;
    
    /*
     * Vector2
     */
    struct INFERNO_API Vector2 {
        //Static Constants
        
        /*
         * Vector2(0, 0)
         */
        static const Vector2 zero;
        
        /*
         * Vector2(1, 0)
         */
        static const Vector2 unit_x;
        
        /*
         * Vector2(0, 1)
         */
        static const Vector2 unit_y;
        
        //Fields
        
        /*
         * X coordinate
         */
        float x;
        
        /*
         * Y coordinate
         */
        float y;
        
        //Constructors
        
        /*
         * Create a new Vector2(0, 0)
         */
        Vector2();
        
        /*
         * Create a new Vector2
         */
        Vector2(float x, float y);
        
        /*
         * Create a new Vector2
         */
        explicit Vector2(float value);
        
        //Static Methods
        
        /*
         * Transform the vector using a matrix
         */
        static Vector2 transform(Vector2 vector, Matrix matrix);
        
        //Methods
        
        /*
         * Get the magnitude of the vector
         */
        float get_magnitude();
        
        /*
         * Get the magnitude of the vector squared
         */
        float get_magnitude_squared();
        
        /*
         * Get the dot product
         */
        float dot(Vector2 b);
        
        /*
         * Get the distance
         */
        float distance(Vector2 b);
        
        /*
         * Check intersection between two lines
         */
        bool intersects(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2);
        
        //Operators
        
        Vector2 operator+(Vector2 b);
        Vector2 operator+(float b);
        void operator+=(Vector2 b);
        void operator+=(float b);
        
        Vector2 operator-(Vector2 b);
        Vector2 operator-(float b);
        void operator-=(Vector2 b);
        void operator-=(float b);
        
        Vector2 operator/(Vector2 b);
        Vector2 operator/(float b);
        void operator/=(Vector2 b);
        void operator/=(float b);
        
        Vector2 operator*(Vector2 b);
        Vector2 operator*(float b);
        void operator*=(Vector2 b);
        void operator*=(float b);
        
        Vector2 operator-();
        bool operator==(Vector2 b);
        bool operator!=(Vector2 b);
    };
}

#endif //INFERNO_VECTOR2_H
