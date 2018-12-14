//
// Created by Reece Mackie on 12/12/18.
//

#ifndef INFERNO_LINECOLLIDER_H
#define INFERNO_LINECOLLIDER_H

#include <vector>

#include "Inferno/Physics/BaseCollider.h"
#include "Inferno/Inferno.h"
#include "Inferno/Line.h"

namespace Inferno {
    namespace Physics {
        /*
         * Collision detector for lines
         */
        class INFERNO_API LineCollider : public BaseCollider {
        public:
            //Fields
            
            /*
             * The lines to check for collisions with
             */
            std::vector<Line> lines;
            
            //Constructors
    
            /*
             * Create a new line collision detector
             */
            LineCollider(Instance* instance, std::vector<Line> lines);
            
            //Methods
            
            bool check_collisions(Vector2 position) override;
    
            /*
             * Determine whether or not a collider is colliding with this one
             */
            bool is_colliding(BaseCollider* b) override;
        };
    }
}

#endif //INFERNO_LINECOLLIDER_H
