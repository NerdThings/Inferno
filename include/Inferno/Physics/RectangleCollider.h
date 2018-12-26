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
        /*
         * Collision detector for rectangles
         */
        class INFERNO_API RectangleCollider : public BaseCollider {
            //Fields
            
            /*
             * Whether or not to use the instance bounds instead of provided rectangle
             */
            bool _use_instance_bounds = false;
        public:
            //Fields
            
            /*
             * The rectangle to check for collisions for.
             * This is only used if the longer constructor is used.
             */
            Rectangle rectangle = Rectangle(0, 0, 0, 0);
            
            //Constructors
    
            /*
             * Create a new rectangle collision detector using an instance's bounds
             */
            explicit RectangleCollider(World::Instance* instance);
            
            /*
             * Create a new rectangle collision detector using a provided rectangle
             */
            RectangleCollider(World::Instance* instance, Rectangle rectangle);
            
            //Methods
            
            bool is_colliding(BaseCollider* b) override;
            
            /*
             * Get the collider rectangle
             */
            Rectangle get_rectangle();
        };
    }
}

#endif //INFERNO_RECTANGLECOLLIDER_H
