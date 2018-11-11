//
// Created by reece on 11/11/18.
//

#pragma once

#include "Scene.h"

using namespace Inferno;

class TestScene : public Scene {
public:
    TestScene(Game* parent_game);
    
    void loaded() override;
    
    void unloaded() override;
};