//
// Created by Reece Mackie on 20/11/18.
//

#ifndef INFERNO_TESTWALL_H
#define INFERNO_TESTWALL_H

#include "Inferno/Instance.h"

class TestWall : public Inferno::Instance {
public:
    TestWall(Inferno::Scene* parent_scene, Inferno::Vector2 position);
    void draw(Inferno::Graphics::Renderer* renderer) override;
};


#endif //INFERNO_TESTWALL_H
