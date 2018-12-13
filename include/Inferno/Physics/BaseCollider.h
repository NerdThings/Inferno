//
// Created by Reece Mackie on 12/12/18.
//

#ifndef INFERNO_BASECOLLIDER_H
#define INFERNO_BASECOLLIDER_H

#include <string>

#include "Inferno/Events/EventHandler.h"
#include "Inferno/Physics/CollisionActionArgs.h"
#include "Inferno/Inferno.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    class Instance;
    
    namespace Physics {
        /*
         * A base collider.
         * This is useful for creating custom collisions.
         * A collider is attached to an Instance.
         */
        class INFERNO_API BaseCollider {
        protected:
            //Fields
            
            /*
             * The instance that the collider is attached to
             */
            Instance* _parent_instance;
            
            //Methods
            
            virtual bool run_check(bool fire_events = false);
        public:
            //Fields
    
            /*
             * The type of instance to check collisions for
             */
            std::string colliding_instance_type = "";
            
            /*
             * Event that is fired for every collision
             */
            Events::EventHandler<Events::Action<CollisionActionArgs>, CollisionActionArgs> on_collide;
            
            //Constructors
            
            /*
             * Create a blank collider
             */
            BaseCollider(Instance* parent_instance);
            
            //Methods
            
            /*
             * Get the base collider as another derived type.
             * Returns nullptr if this is not a member of the provided type
             */
            template<typename T>
            T* as(){
                return dynamic_cast<T*>(this);
            }
    
            /*
             * Check for collisions
             */
            virtual bool check_collisions();
            
            /*
             * Check for collisions at position
             */
            virtual bool check_collisions(Vector2 position);
            
            /*
             * Check if this collider collides with another.
             */
            virtual bool is_colliding(BaseCollider* b);
            
            /*
             * Run events
             */
            virtual void update();
        };
    }
}

#endif //INFERNO_BASECOLLIDER_H
