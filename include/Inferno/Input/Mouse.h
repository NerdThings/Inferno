//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_MOUSE_H
#define INFERNO_MOUSE_H

#include "Inferno/Graphics/Camera.h"
#include "Inferno/Input/MouseState.h"
#include "Inferno/Inferno.h"
#include "Inferno/Matrix.h"

namespace Inferno {
    class Game;
    
    namespace Input {
        /*
         * Inferno Mouse host
         */
        class INFERNO_API Mouse {
        public:
            //Internal Static Fields
#ifdef INFERNO
            /*
             * Scroll X position
             */
            static int internal_scroll_x;
            
            /*
             * Scroll Y position
             */
            static int internal_scroll_y;
            
            /*
             * Left button state
             */
            static bool internal_left;
            
            /*
             * Middle button state
             */
            static bool internal_middle;
            
            /*
             * Right button state
             */
            static bool internal_right;
            
            /*
             * X1 button state
             */
            static bool internal_x1;
            
            /*
             * X2 button state
             */
            static bool internal_x2;
            
            /*
             * X position
             */
            static int internal_x;
            
            /*
             * Y position
             */
            static int internal_y;
            
            /*
             * The matrix used for transforming the mouse position
             */
            static Matrix transform_matrix;
#endif
            
            //Static Methods
            
            /*
             * Clear the left button
             */
            static void clear_left_button();
            
            /*
             * Clear the right button
             */
            static void clear_middle_button();
            
            /*
             * Clear the right button
             */
            static void clear_right_button();
            
            /*
             * Clear the X1 button
             */
            static void clear_x_button_1();
            
            /*
             * Clear the X2 button
             */
            static void clear_x_button_2();
            
            /*
             * Get the current mouse state
             */
            static MouseState get_state(Game* current_game);
            
            /*
             * Use a camera to transform the mouse position
             * This will use the inverse matrix as we want to scale back into the view
             */
            static void use_camera(Graphics::Camera* camera);
    
            /*
             * Use a matrix to transform the mouse position
             */
            static void use_transform_matrix(Matrix matrix);
        };
    }
}

#endif //INFERNO_MOUSE_H
