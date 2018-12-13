//
// Created by Reece Mackie on 12/12/18.
//

#ifndef INFERNO_LINECOLLIDER_H
#define INFERNO_LINECOLLIDER_H

#include <vector>

#include "Inferno/Physics/BaseCollider.h"
#include "Inferno/Line.h"

namespace Inferno {
    namespace Physics {
        class LineCollider : public BaseCollider {
        public:
            //Fields
            
            std::vector<Line> lines;
            
            //Constructors
    
            LineCollider(Instance* instance, std::vector<Line> lines);
            
            //Methods
            
            bool check_collisions(Vector2 position) override;
            bool is_colliding(BaseCollider* b) override;
        };
    }
}

#endif //INFERNO_LINECOLLIDER_H
