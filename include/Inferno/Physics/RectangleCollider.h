//
// Created by Reece Mackie on 12/12/18.
//

#ifndef INFERNO_RECTANGLECOLLIDER_H
#define INFERNO_RECTANGLECOLLIDER_H

#include "Inferno/Physics/BaseCollider.h"
#include "Inferno/Inferno.h"
#include "Inferno/Rectangle.h"

namespace Inferno {
    namespace Physics {
        class INFERNO_API RectangleCollider : public BaseCollider {
            //Fields
            
            bool _use_instance_bounds = false;
        public:
            //Fields
            
            Rectangle rectangle = Rectangle(0, 0, 0, 0);
            
            //Constructors
    
            explicit RectangleCollider(Instance* instance);
            RectangleCollider(Instance* instance, Rectangle rectangle);
            
            //Methods
            
            bool is_colliding(BaseCollider* b) override;
            Rectangle get_rectangle();
        };
    }
}

#endif //INFERNO_RECTANGLECOLLIDER_H
