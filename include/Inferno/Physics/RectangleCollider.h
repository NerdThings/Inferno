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
            //Methods
            
            bool run_check(bool fire_events = false) override;
        public:
            
            //Constructors
            
            RectangleCollider(Instance* instance);
            
            //Methods
            
            bool check_collisions() override;
            bool check_collisions(Vector2 position) override;
            Rectangle get_rectangle();
            void update() override;
        };
    }
}

#endif //INFERNO_RECTANGLECOLLIDER_H
