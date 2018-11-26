//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_KEYBOARDSTATE_H
#define INFERNO_KEYBOARDSTATE_H

#include "Inferno/Inferno.h"

#include <vector>

#include "Key.h"

namespace Inferno {
    namespace Input {
        struct INFERNO_API KeyboardState {
        private:
            //Fields
            
            unsigned int keys0, keys1, keys2, keys3, keys4, keys5, keys6, keys7;
            
            //Methods
            
            bool private_get_key(Key key);
            void private_set_key(Key key);
            void private_clear_key(Key key);
            void private_clear_all_keys();
        public:
            //Fields
            
            bool caps_lock = false;
            bool num_lock = false;
            
            //Constructors
            
            explicit KeyboardState(std::vector<Key> keys, bool caps_lock = false, bool num_lock = false);
            
            //Methods
            
            bool is_key_down(Key key);
            bool is_key_up(Key key);
            
            //Operators
            
            bool operator==(KeyboardState b);
            bool operator!=(KeyboardState b);
        };
    }
}

#endif //INFERNO_KEYBOARDSTATE_H
