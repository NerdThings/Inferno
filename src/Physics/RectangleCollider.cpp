//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/CircleCollider.h"
#include "Inferno/Physics/RectangleCollider.h"
#include "Inferno/Instance.h"
#include "Inferno/Scene.h"

namespace Inferno {
    namespace Physics {
        //Private methods
        
        bool RectangleCollider::run_check(bool fire_events) {
            //Pass variable
            bool pass = false;
            
            //Get the current scene
            Scene* current_scene = _parent_instance->parent_scene;
        
            //Get all instances spatially near the parent instance
            std::vector<Instance*> nearby = current_scene->get_nearby_instances(_parent_instance);
        
            //Search for a rectangle collision with other colliders
            for (Instance* instance : nearby) {
                if (instance == _parent_instance || instance->type != colliding_instance_type)
                    continue;
    
                //Get colliders
                CircleCollider* circle_collider = instance->collider->as<CircleCollider>();
                RectangleCollider* rect_collider = instance->collider->as<RectangleCollider>();
                
                //Collider types
                if (rect_collider != nullptr) {
                    if (get_rectangle().intersects(rect_collider->get_rectangle())) {
                        pass = true;
                        if (fire_events) {
                            on_collide.invoke(CollisionActionArgs(instance));
                        } else {
                            break;
                        }
                    }
                } else if (circle_collider != nullptr) {
                    if (circle_collider->circle.intersects(get_rectangle())) {
                        pass = true;
                        if (fire_events) {
                            on_collide.invoke(CollisionActionArgs(instance));
                        } else {
                            break;
                        }
                    }
                } else {
                    //TODO: Do collision checks for other colliders
                }
            }
                   
            return pass;
        }
        
        //Constructors
        
        RectangleCollider::RectangleCollider(Inferno::Instance *instance) : BaseCollider(instance) {
        
        }
        
        //Methods
        
        bool RectangleCollider::check_collisions() {
            return run_check();
        }
    
        bool RectangleCollider::check_collisions(Vector2 position) {
            //Save current position
            Vector2 last_position = _parent_instance->get_position();
            
            //Set to target position
            _parent_instance->set_position(position);                    
            
            //Check for collision
            bool pass = run_check();
        
            //Restore position
            _parent_instance->set_position(last_position);
            
            return pass;
        }
    
        Rectangle RectangleCollider::get_rectangle() {
            return _parent_instance->get_bounds();
        }
        
        void RectangleCollider::update() {
            run_check(true);
        }
    }
}
