//
// Created by Reece Mackie on 17/11/18.
//

#include "Inferno/Input/KeyboardState.h"

namespace Inferno {
    namespace Input {
        //Private methods
        
        bool KeyboardState::private_get_key(Inferno::Input::Key key) {
            unsigned int mask = (unsigned int)1 << (int(key) & 0x1f);
            
            unsigned int element;
            int e = (int(key) >> 5);
            switch (e) {
                case 0 : element = keys0; break;
                case 1 : element = keys1; break;
                case 2 : element = keys2; break;
                case 3 : element = keys3; break;
                case 4 : element = keys4; break;
                case 5 : element = keys5; break;
                case 6 : element = keys6; break;
                case 7 : element = keys7; break;
                default: element = 0; break;
            }
            
            return (element & mask) != 0;
        }
        
        void KeyboardState::private_set_key(Key key) {
            unsigned int mask = (unsigned int)1 << (((int)key) & 0x1f);
            int e = (int(key) >> 5);
            switch (e)
            {
                case 0: keys0 |= mask; break;
                case 1: keys1 |= mask; break;
                case 2: keys2 |= mask; break;
                case 3: keys3 |= mask; break;
                case 4: keys4 |= mask; break;
                case 5: keys5 |= mask; break;
                case 6: keys6 |= mask; break;
                case 7: keys7 |= mask; break;
            }
        }
        
        void KeyboardState::private_clear_key(Key key) {
            unsigned int mask = (unsigned int)1 << (((int)key) & 0x1f);
            int e = (int(key) >> 5);
            switch (e)
            {
                case 0: keys0 &= ~mask; break;
                case 1: keys1 &= ~mask; break;
                case 2: keys2 &= ~mask; break;
                case 3: keys3 &= ~mask; break;
                case 4: keys4 &= ~mask; break;
                case 5: keys5 &= ~mask; break;
                case 6: keys6 &= ~mask; break;
                case 7: keys7 &= ~mask; break;
            }
        }
        
        void KeyboardState::private_clear_all_keys() {
            keys0 = 0;
            keys1 = 0;
            keys2 = 0;
            keys3 = 0;
            keys4 = 0;
            keys5 = 0;
            keys6 = 0;
            keys7 = 0;
        }
        
        //Constructors
        
        KeyboardState::KeyboardState(std::vector<Inferno::Input::Key> keys, bool caps_lock, bool num_lock) {
            this->caps_lock = caps_lock;
            this->num_lock = num_lock;
    
            keys0 = 0;
            keys1 = 0;
            keys2 = 0;
            keys3 = 0;
            keys4 = 0;
            keys5 = 0;
            keys6 = 0;
            keys7 = 0;
            
            for (Key k : keys)
                private_set_key(k);
        }
        
        //Methods
        
        bool KeyboardState::is_key_down(Inferno::Input::Key key) {
            return private_get_key(key);
        }
        
        bool KeyboardState::is_key_up(Inferno::Input::Key key) {
            return !private_get_key(key);
        }
        
        //Operators
        
        bool KeyboardState::operator==(Inferno::Input::KeyboardState b) {
            return keys0 == b.keys0
                   && keys1 == b.keys1
                   && keys2 == b.keys2
                   && keys3 == b.keys3
                   && keys4 == b.keys4
                   && keys5 == b.keys5
                   && keys6 == b.keys6
                   && keys7 == b.keys7;
        }
        
        bool KeyboardState::operator!=(Inferno::Input::KeyboardState b) {
            return !(*this == b);
        }
    }
}