//
// Created by Reece Mackie on 20/11/18.
//

#ifndef INFERNO_TESTWALL_H
#define INFERNO_TESTWALL_H

#include "Inferno/World/Instance.h"

using namespace Inferno;

class TestWall : public World::Instance {
public:
    TestWall(Scene* parent_scene, Vector2 position);
    void draw(Graphics::Renderer* renderer) override;
};


#endif //INFERNO_TESTWALL_H
