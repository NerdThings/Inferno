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
        public:
            //Fields
            
            Circle circle;
            
            //Constructors
            
            explicit CircleCollider(Instance* instance);
            
            //Methods
    
            bool is_colliding(BaseCollider* b) override;
        };
    }
}

#endif //INFERNO_CIRCLECOLLIDER_H
