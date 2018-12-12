//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/RectangleCollider.h"
#include "Inferno/Instance.h"
#include "Inferno/Scene.h"

namespace Inferno {
    namespace Physics {
        //Constructors
        
        RectangleCollider::RectangleCollider(Inferno::Instance *instance) : BaseCollider(instance) {
        
        }
        
        //Methods
        
        bool RectangleCollider::check_collisions() {
            return check_collisions(_parent_instance->get_position());
        }
    
        bool RectangleCollider::check_collisions(Vector2 position) {
            //Save current position
            Vector2 last_position = _parent_instance->get_position();
            
            //Set to target position
            _parent_instance->set_position(position);
            
            //Get the current scene
            Scene* current_scene = _parent_instance->parent_scene;
        
            //Get all instances spatially near the parent instance
            std::vector<Instance*> nearby = current_scene->get_nearby_instances(_parent_instance);
        
            //Search for a rectangle collision with other colliders
            for (Instance* instance : nearby) {
                if (instance == _parent_instance || instance->type != colliding_instance_type)
                    continue;
            
                //Rectangle colliders
                auto * rect_collider = dynamic_cast<RectangleCollider*>(instance->collider);
                if (rect_collider != nullptr) {
                    if (get_rectangle().intersects(rect_collider->get_rectangle())) {
                        //Restore position
                        _parent_instance->set_position(last_position);
                        return true;
                    }
                } else {
                    //TODO: Do collision checks for other colliders
                }
            }
        
            //Restore position
            _parent_instance->set_position(last_position);
            
            return false;
        }
    
        Rectangle RectangleCollider::get_rectangle() {
            return _parent_instance->get_bounds();
        }
        
        void RectangleCollider::update() {
            Scene* current_scene = _parent_instance->parent_scene;
    
            //Get all instances spatially near the parent instance
            std::vector<Instance*> nearby = current_scene->get_nearby_instances(_parent_instance);
    
            //Search for a rectangle collision with other colliders
            for (Instance* instance : nearby) {
                if (instance == _parent_instance || instance->type != colliding_instance_type)
                    continue;
    
                //Rectangle colliders
                auto * rect_collider = dynamic_cast<RectangleCollider*>(instance->collider);
                if (rect_collider != nullptr) {
                    if (get_rectangle().intersects(rect_collider->get_rectangle())) {
                        //Fire collision events
                        on_collide.invoke(CollisionActionArgs(instance));
                    }
                } else {
                    //TODO: Do collision checks for other colliders
                }
            }
        }
    }
}