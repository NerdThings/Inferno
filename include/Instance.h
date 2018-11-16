//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_INSTANCE_H
#define INFERNO_INSTANCE_H

#include "Inferno.h"

#include "Scene.h"
#include "Vector2.h"

namespace Inferno {
    class INFERNO_API Instance {
    protected:
        bool affected_by_gravity = false;
        float depth = 0;
        bool draws = false;
        bool inherit_parent = true;
        Instance* parent = nullptr;
        Scene* parent_scene = nullptr;
        Vector2 position = Vector2(0, 0);
        float roughness = 0;
        //TODO: Sprite class
        bool updates = false;
        Vector2 velocity = Vector2(0, 0);
    };
}

#endif //INFERNO_INSTANCE_H
