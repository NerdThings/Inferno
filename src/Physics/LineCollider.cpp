//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/LineCollider.h"

namespace Inferno {
    namespace Physics {
        //Constructors
        
        LineCollider::LineCollider(Instance *instance, std::vector<Vector2> points) : BaseCollider(instance), points(points) {
        
        }
        
        //Methods
        
        bool LineCollider::check_collisions() {
        
        }
        
        bool LineCollider::check_collisions(Vector2 position) {
            
        }
        
        void LineCollider::update() {
        
        }
    }
}