//
// Created by Reece Mackie on 12/12/18.
//

#ifndef INFERNO_LINECOLLIDER_H
#define INFERNO_LINECOLLIDER_H

#include <vector>

#include "Inferno/Physics/BaseCollider.h"

namespace Inferno {
    namespace Physics {
        class LineCollider : public BaseCollider {
        public:
            //Fields
            
            std::vector<Vector2> points;
            
            //Constructors
    
            LineCollider(Instance* instance, std::vector<Vector2> points);
            
            //Methods
            
            bool check_collisions() override;
            bool check_collisions(Vector2 position) override;
            void update() override;
        };
    }
}

#endif //INFERNO_LINECOLLIDER_H
