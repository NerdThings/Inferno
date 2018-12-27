//
// Created by Reece Mackie on 27/12/2018.
//

#include "Inferno/World/UpdatableInstance.h"

namespace Inferno {
    namespace World {
        //Constructors

        UpdatableInstance::UpdatableInstance(Scene* parent_scene) : Instance(parent_scene) {}

        UpdatableInstance::UpdatableInstance(Scene* parent_scene, Vector2 position, float depth) : Instance(parent_scene, position, depth) {}

        //Methods

        void UpdatableInstance::begin_update() {
            //TODO: Physics instance
            //Check for collisions so that the code can handle it
            if (collider != nullptr)
                collider->update();
        }

        void UpdatableInstance::end_update() {
            //TODO: Physics instance
            //Apply velocity
            _position = _position + velocity;
        }

        void UpdatableInstance::update() {

        }
    }
}