//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_MOUSE_H
#define INFERNO_MOUSE_H

#include "Inferno.h"

#include "Input/MouseState.h"
#include "Matrix.h"

namespace Inferno {
    class Game;
    
    namespace Input {
        class INFERNO_API Mouse {
        public:
            //Internal Static Fields
#ifdef INFERNO
            static int internal_scroll_x;
            static int internal_scroll_y;
            static bool internal_left;
            static bool internal_middle;
            static bool internal_right;
            static bool internal_x1;
            static bool internal_x2;
            static int internal_x;
            static int internal_y;
#endif
            
            //Static Methods
            
            static void clear_left_button();
            static void clear_middle_button();
            static void clear_right_button();
            static void clear_x_button_1();
            static void clear_x_button_2();
            static MouseState get_state(Game* current_game, Matrix* translation_matrix = nullptr);
        };
    }
}

#endif //INFERNO_MOUSE_H
