//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_MOUSESTATE_H
#define INFERNO_MOUSESTATE_H

#include "Inferno/Inferno.h"

#include "ButtonState.h"

namespace Inferno {
    namespace Input {
        /*
         * Mouse State
         */
        struct INFERNO_API MouseState {
            //Fields
            
            /*
             * The X position
             */
            int x;
            
            /*
             * The Y position
             */
            int y;
            
            /*
             * Scroll wheel Y value
             */
            int scroll_wheel_y;
            
            /*
             * Scroll wheel X value
             */
            int scroll_wheel_x;
            
            /*
             * Left button state
             */
            ButtonState left_button;
            
            /*
             * Middle button state
             */
            ButtonState middle_button;
    
            /*
             * Right button state
             */
            ButtonState right_button;
    
            /*
             * X1 button state
             */
            ButtonState x_button_1;
    
            /*
             * X2 button state
             */
            ButtonState x_button_2;
    
            //Constructors
            
            /*
             * Create an empty mouse state
             */
            MouseState();
            
            /*
             * Create a mouse state
             */
            MouseState(int x, int y, int scrollx, int scrolly, ButtonState left, ButtonState middle, ButtonState right, ButtonState x1, ButtonState x2);
        };
    }
}

#endif //INFERNO_MOUSESTATE_H
