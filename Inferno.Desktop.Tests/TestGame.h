//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_TESTGAME_H
#define INFERNO_TESTGAME_H

#include "Inferno/Graphics/Shader.h"
#include "Inferno/Game.h"

#include "TestScene.h"

class TestGame : public Inferno::Game {
    TestScene* test_scene;
    Inferno::Graphics::Shader* test_vshader;
    Inferno::Graphics::Shader* test_fshader;
public:
    TestGame();
};


#endif //INFERNO_TESTGAME_H
