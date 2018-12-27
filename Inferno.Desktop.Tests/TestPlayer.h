//
// Created by Reece Mackie on 19/11/18.
//

#ifndef INFERNO_TESTPLAYER_H
#define INFERNO_TESTPLAYER_H

#include "Inferno/World/Instance.h"
#include "Inferno/World/UpdatableInstance.h"

using namespace Inferno;

class TestPlayer : public World::UpdatableInstance {
public:
    explicit TestPlayer(Scene* parent_scene);
    void update() override;
    void draw(Graphics::Renderer* renderer) override;
};


#endif //INFERNO_TESTPLAYER_H
