//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_VECTOR3_H
#define INFERNO_VECTOR3_H

#include "Inferno/Inferno.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    struct Matrix;
    
    /*
     * Vector3
     */
    struct INFERNO_API Vector3 {
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
    
        //Constructors
        
        /*
         * Create new Vector3(0, 0, 0)
         */
        Vector3();
        
        /*
         * Create new Vector3
         */
        Vector3(float x, float y, float z);
    
        /*
         * Create new Vector3
         */
        Vector3(Vector2 value, float z);
    
        /*
         * Create new Vector3
         */
        explicit Vector3(float value);
    
        //Static Methods
    
        /*
         * Transform the vector using a matrix
         */
        static Vector3 transform(Vector3 vector, Matrix matrix);
    
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
        float dot(Vector3 b);
    
        /*
         * Get the distance
         */
        float distance(Vector3 b);
    
        //Operators
        Vector3 operator+(Vector3 b);
        Vector3 operator+(int b);
        Vector3 operator+(float b);
        Vector3 operator-(Vector3 b);
        Vector3 operator-(int b);
        Vector3 operator-(float b);
        Vector3 operator*(Vector3 b);
        Vector3 operator*(int b);
        Vector3 operator*(float b);
        Vector3 operator/(Vector3 b);
        Vector3 operator/(int b);
        Vector3 operator/(float b);
        Vector3 operator-();
        bool operator==(Vector3 b);
        bool operator!=(Vector3 b);
    };
}

#endif //INFERNO_VECTOR3_H
