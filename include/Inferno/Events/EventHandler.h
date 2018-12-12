//
// Created by Reece Mackie on 06/12/18.
//

#ifndef INFERNO_EVENTHANDLER_H
#define INFERNO_EVENTHANDLER_H

#include <vector>

#include "Inferno/Events/Action.h"
#include "Inferno/Events/ActionArgs.h"

namespace Inferno {
    namespace Events {
        /*
         * An event handler which has subscribed actions
         */
        template<typename T, typename TArgs = ActionArgs>
        class EventHandler {
            //Fields
            
            /*
             * Vector of subscribed actions
             */
            std::vector<T*> _actions;
        public:
            
            //Constructors
            
            /*
             * Create a new event handler
             */
            EventHandler() {
                (void)static_cast<Action<TArgs>*>((T*)0);
            }
            
            //Methods
            
            /*
             * Clear the subscribed actions
             */
            void clear_subscriptions() {
                _actions.clear();
            }
    
            /*
             * Invoke event, in turn invoking all subscribed actions
             */
            void invoke() {
                for (T* a : _actions) {
                    //There is no safeguard because we want an error here if something is wrong
                    dynamic_cast<Action<TArgs>*>(a)->invoke();
                }
            }
            
            /*
             * Invoke event with args, in turn invoking all subscribed actions
             */
            void invoke(TArgs args) {
                for (T* a : _actions) {
                    //There is no safeguard because we want an error here if something is wrong
                    dynamic_cast<Action<TArgs>*>(a)->invoke(args);
                }
            }
            
            /*
             * Subscribe to an action to this event handler
             */
            void subscribe(T* action) {
                _actions.emplace_back(action);
            }
        };
    }
}

#endif //INFERNO_EVENTHANDLER_H
