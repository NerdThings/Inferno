//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_VECTOR4_H
#define INFERNO_VECTOR4_H

#include "Inferno/Inferno.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"

namespace Inferno {
    struct INFERNO_API Vector4 {
        //Fields
    
        /*
         * X coordinate
         */
        float x;
        
        /*
         * Y coordinate
         */
        float y;
        
        /*
         * Z coordinate
         */
        float z;
        
        /*
         * W coordinate
         */
        float w;
    
        //Constructors
    
        /*
         * Create new Vector4(0, 0, 0, 0)
         */
        Vector4();
        
        /*
         * Create new Vector4
         */
        Vector4(float x, float y, float z, float w);
    
        /*
         * Create new Vector4
         */
        Vector4(Vector2 value, float z, float w);
    
        /*
         * Create new Vector4
         */
        Vector4(Vector3 value, float w);
    
        /*
         * Create new Vector4
         */
        explicit Vector4(float value);
    
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
        float dot(Vector4 b);
    
        /*
         * Get the distance
         */
        float distance(Vector4 b);
    
        //Operators
    
        Vector4 operator+(Vector4 b);
        Vector4 operator+(int b);
        Vector4 operator+(float b);
        Vector4 operator-(Vector4 b);
        Vector4 operator-(int b);
        Vector4 operator-(float b);
        Vector4 operator*(Vector4 b);
        Vector4 operator*(int b);
        Vector4 operator*(float b);
        Vector4 operator/(Vector4 b);
        Vector4 operator/(int b);
        Vector4 operator/(float b);
        Vector4 operator-();
        bool operator==(Vector4 b);
        bool operator!=(Vector4 b);
    };
}

#endif //INFERNO_VECTOR4_H
