//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_KEYBOARD_H
#define INFERNO_KEYBOARD_H

#include "Inferno/Inferno.h"

#include <vector>

#include "Key.h"
#include "KeyboardState.h"

namespace Inferno {
    namespace Input {
        class INFERNO_API Keyboard {
        public:
#ifdef INFERNO
            static std::vector<Key> internal_keys;
#endif
            
            //Methods
            
            static KeyboardState get_state();
        };
    }
}

#endif //INFERNO_KEYBOARD_H
