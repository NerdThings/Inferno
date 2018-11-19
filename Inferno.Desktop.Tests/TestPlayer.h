//
// Created by Reece Mackie on 19/11/18.
//

#ifndef INFERNO_TESTPLAYER_H
#define INFERNO_TESTPLAYER_H

#include "Instance.h"

class TestPlayer : public Inferno::Instance {
public:
    TestPlayer(Inferno::Scene* parent_scene);
    void update() override;
    void draw(Inferno::Graphics::Renderer* renderer) override;
};


#endif //INFERNO_TESTPLAYER_H
