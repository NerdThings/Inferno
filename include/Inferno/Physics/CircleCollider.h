//
// Created by Reece Mackie on 12/12/18.
//

#ifndef INFERNO_CIRCLECOLLIDER_H
#define INFERNO_CIRCLECOLLIDER_H

#include "Inferno/Physics/BaseCollider.h"
#include "Inferno/Inferno.h"
#include "Inferno/Circle.h"

namespace Inferno {
    namespace Physics {
        /*
         * Collision detector for circles
         */
        class INFERNO_API CircleCollider : public BaseCollider {
        public:
            //Fields
            
            /*
             * The circle to check for collisions with
             */
            Circle circle;
            
            //Constructors
            
            /*
             * Create a new circle collision detector
             */
            explicit CircleCollider(Instance* instance);
            
            //Methods
    
            /*
             * Determine whether or not a collider is colliding with this one
             */
            bool is_colliding(BaseCollider* b) override;
        };
    }
}

#endif //INFERNO_CIRCLECOLLIDER_H
