//
// Created by Reece Mackie on 26/12/2018.
//

#ifndef INFERNO_UPDATABLEINSTANCE_H
#define INFERNO_UPDATABLEINSTANCE_H

#include "Inferno/World/Instance.h"
#include "Inferno/Inferno.h"

namespace Inferno {
    namespace World {
        class INFERNO_API UpdatableInstance : public Instance {
        public:
            //Construcors

            UpdatableInstance(Scene* parent_scene);

            UpdatableInstance(Scene* parent_scene, Vector2 position, float depth);

            //Methods

            /*
             * Begin updating the instance
             */
            virtual void begin_update();

            /*
            * End instance update
            */
            virtual void end_update();

            /*
             * Update the instance
             */
            virtual void update();
        };
    }
}

#endif //INFERNO_UPDATABLEINSTANCE_H
