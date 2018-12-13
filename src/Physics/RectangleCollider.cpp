//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/CircleCollider.h"
#include "Inferno/Physics/LineCollider.h"
#include "Inferno/Physics/RectangleCollider.h"
#include "Inferno/Instance.h"
#include "Inferno/Scene.h"

namespace Inferno {
    namespace Physics {
        //Constructors
        
        RectangleCollider::RectangleCollider(Instance *instance) : BaseCollider(instance), _use_instance_bounds(true) {}
        
        RectangleCollider::RectangleCollider(Instance *instance, Rectangle rectangle) : BaseCollider(instance), rectangle(rectangle) {}
        
        //Methods

        bool RectangleCollider::is_colliding(BaseCollider* b) {
            //Get colliders
            auto* circle_collider = b->as<CircleCollider>();
            auto* line_collider = b->as<LineCollider>();
            auto* rect_collider = b->as<RectangleCollider>();
    
            //Collider types
            if (rect_collider != nullptr) {
                if (get_rectangle().intersects(rect_collider->get_rectangle())) {
                    return true;
                }
            } else if (line_collider != nullptr) {
                //TODO
                //for (Line line : line_collider->lines) {
                //    if (get_rectangle().intersects(line))
                //        return true;
                //}
            } else if (circle_collider != nullptr) {
                if (circle_collider->circle.intersects(get_rectangle())) {
                    return true;
                }
            } else {
                //TODO: Do collision checks for other colliders
            }
            
            return false;
        }
        
        Rectangle RectangleCollider::get_rectangle() {
            if (_use_instance_bounds)
                return _parent_instance->get_bounds();
            return rectangle;
        }
    }
}
