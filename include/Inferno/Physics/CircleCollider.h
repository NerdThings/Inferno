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
        class INFERNO_API CircleCollider : public BaseCollider {
            //Methods
            
            bool run_check(bool fire_events = false) override;
        public:
            //Fields
            
            Circle circle;
            
            //Constructors
            
            CircleCollider(Instance* instance);
            
            //Methods
    
            bool check_collisions() override;
            bool check_collisions(Vector2 position) override;
            void update() override;
        };
    }
}

#endif //INFERNO_CIRCLECOLLIDER_H
