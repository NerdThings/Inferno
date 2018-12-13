//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/CircleCollider.h"
#include "Inferno/Physics/RectangleCollider.h"
#include "Inferno/Instance.h"
#include "Inferno/Scene.h"

namespace Inferno {
    namespace Physics {
        //Constructors
        
        CircleCollider::CircleCollider(Inferno::Instance *instance) : BaseCollider(instance) {}
        
        //Methods

        bool CircleCollider::is_colliding(BaseCollider* b) {
            //Get colliders
            CircleCollider* circle_collider = b->as<CircleCollider>();
            RectangleCollider* rect_collider = b->as<RectangleCollider>();
    
            //Collider types
            if (circle_collider != nullptr) {
                if (circle.intersects(circle_collider->circle)) {
                    return true;
                }
            } else if (rect_collider != nullptr) {
                if (circle.intersects(rect_collider->get_rectangle())) {
                    return true;
                }
            } else {
                //TODO: Do collision checks for other colliders
            }
            
            return false;
        }
    }
}