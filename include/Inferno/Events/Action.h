//
// Created by Reece Mackie on 06/12/18.
//

#ifndef INFERNO_ACTION_H
#define INFERNO_ACTION_H

#include "Inferno/Events/ActionArgs.h"

namespace Inferno {
    namespace Events {
        /*
         * An action which can be used to subscribe to an event handler
         */
        template <typename TArgs = ActionArgs>
        class Action {
        public:
            //Constructors
            
            /*
             * Create a new base action
             */
            Action() = default;
            
            //Methods
    
            /*
             * Invoke the action
             */
            virtual void invoke() {}
            
            /*
             * Invoke the action with args
             */
            virtual void invoke(TArgs args) {}
        };
    }
}

#endif //INFERNO_ACTION_H
