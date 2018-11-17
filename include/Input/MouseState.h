//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_MOUSESTATE_H
#define INFERNO_MOUSESTATE_H

#include "Inferno.h"

#include "ButtonState.h"

namespace Inferno {
    namespace Input {
        struct INFERNO_API MouseState {
            //Fields
            
            int x;
            int y;
            int scroll_wheel_y;
            int scroll_wheel_x;
            ButtonState left_button;
            ButtonState middle_button;
            ButtonState right_button;
            ButtonState x_button_1;
            ButtonState x_button_2;
    
            //Constructors
            
            MouseState();
            MouseState(int x, int y, int scrollx, int scrolly, ButtonState left, ButtonState middle, ButtonState right, ButtonState x1, ButtonState x2);
        };
    }
}

#endif //INFERNO_MOUSESTATE_H
