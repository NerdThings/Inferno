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
         */
        class INFERNO_API BaseCollider {
        protected:
            //Fields
            
            Instance* _parent_instance;
        public:
            //Fields
    
            std::string colliding_instance_type = "";
            Events::EventHandler<Events::Action<CollisionActionArgs>, CollisionActionArgs> on_collide;
            
            //Constructors
            
            BaseCollider(Instance* parent_instance);
            
            //Methods
    
            virtual bool check_collisions();
            virtual bool check_collisions(Vector2 position);
            virtual void update();
        };
    }
}

#endif //INFERNO_BASECOLLIDER_H
