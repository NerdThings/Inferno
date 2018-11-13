//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_MATRIX_H
#define INFERNO_MATRIX_H

#include "Inferno.h"

namespace Inferno {
    struct Vector3;
    
    struct INFERNO_API Matrix {
        //Fields
        
        float m11;
        float m12;
        float m13;
        float m14;
        float m21;
        float m22;
        float m23;
        float m24;
        float m31;
        float m32;
        float m33;
        float m34;
        float m41;
        float m42;
        float m43;
        float m44;
        
        //Constructors
        
        Matrix();
        Matrix(float m11, float m12, float m13, float m14,
               float m21, float m22, float m23, float m24,
               float m31, float m32, float m33, float m34,
               float m41, float m42, float m43, float m44);
        
        //Static Methods
        //static Matrix create_billboard(Vector3 object_position, Vector3 camera_position, Vector3 camera_up_vector, Vector3* camera_forward_vector);
        //static Matrix create_constrained_billboard(Vector3 object_position, Vector3 camera_position, Vector3 rotate_axis, Vector3* camera_forward_vector, Vector3* object_forward_vector);
        //static Matrix create_from_axis_angle(Vector3 axis, float angle);
        //static Matrix create_from_quaternion(Quaternion quaternion);
        //static Matrix create_from_yaw_pitch_roll(float yaw, float pitch, float roll);
        //static Matrix create_look_at(Vector3 camera_position, Vector3 camera_target, Vector3 camera_up_vector);
        static Matrix create_orthographic(float width, float height, float z_near, float z_far);
        static Matrix create_orthographic_off_center(float left, float right, float bottom, float top, float z_near, float z_far);
        //static Matrix create_perspective(float width, float height, float near_plane_distance, float far_plane_distance);
        //static Matrix create_perspective_field_of_view(float field_of_view, float aspect_ration, float near_plane_distance, float far_plane_distance);
        //static Matrix create_perspective_off_center(float left, float right, float bottom, float top, float near_plane_distance, float far_plane_distance);
        static Matrix create_rotation_x(float radians);
        static Matrix create_rotation_y(float radians);
        static Matrix create_rotation_z(float radians);
        static Matrix create_scale(float scale);
        static Matrix create_scale(Vector3 scale);
        static Matrix create_scale(float x_scale, float y_scale, float z_scale);
        //static Matrix create_shadow(Vector3 light_direction, Plane plane);
        static Matrix create_translation(float x_position, float y_position, float z_position);
        static Matrix create_translation(Vector3 position);
        //static Matrix create_reflection(Plane value);
        //static Matrix create_world(Vector3 position, Vector3 forward, Vector3 up)
        static Matrix invert(Matrix matrix);
        //static Matrix lerp(Matrix matrix1, Matrix matrix2, float amount);
        //static Matrix transpose(Matrix matrix);
        
        //Methods
        
        //bool decompose(Vector3* scale, Quaternion* rotation, Vector3* translation);
        //float determinant();
        Vector3 get_backward_vector();
        Vector3 get_down_vector();
        Vector3 get_forward_vector();
        Vector3 get_left_vector();
        Vector3 get_right_vector();
        Vector3 get_scale_vector();
        Vector3 get_translation_vector();
        Vector3 get_up_vector();
        float* to_float_array();
    
        //Operators
        Matrix operator+(Matrix b);
        Matrix operator-(Matrix b);
        Matrix operator/(Matrix b);
        Matrix operator/(int b);
        Matrix operator/(float b);
        Matrix operator*(Matrix b);
        Matrix operator*(int b);
        Matrix operator*(float b);
        Matrix operator-();
        bool operator==(Matrix b);
        bool operator!=(Matrix b);
    };
}

#endif //INFERNO_MATRIX_H
