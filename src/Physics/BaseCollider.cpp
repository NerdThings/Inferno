//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/BaseCollider.h"

namespace Inferno {
    namespace Physics {
        //Private Methods
        
        bool BaseCollider::run_check(bool fire_events) {
            return false;
        }
        
        //Constructors
        
        BaseCollider::BaseCollider(Inferno::Instance *parent_instance) {
            _parent_instance = parent_instance;
        }
        
        //Methods
        
        bool BaseCollider::check_collisions(){
            //Do nothing, this collider is just a base
            return false;
        }
    
        bool BaseCollider::check_collisions(Vector2 position){
            //Do nothing, this collider is just a base
            return false;
        }
        
        void BaseCollider::update() {
            //Do nothing, this collider is just a base
        }
    }
}