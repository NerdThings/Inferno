//
// Created by Reece Mackie on 19/11/18.
//

#ifndef INFERNO_TESTPLAYER_H
#define INFERNO_TESTPLAYER_H

#include "Inferno/Instance.h"

class TestPlayer : public Inferno::Instance {
public:
    explicit TestPlayer(Inferno::Scene* parent_scene);
    void update() override;
    void draw(Inferno::Graphics::Renderer* renderer) override;
};


#endif //INFERNO_TESTPLAYER_H
