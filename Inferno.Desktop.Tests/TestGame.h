//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_TESTGAME_H
#define INFERNO_TESTGAME_H

#include "Game.h"

#include "TestScene.h"

class TestGame : public Inferno::Game {
    TestScene* test_scene;
public:
    TestGame();
};


#endif //INFERNO_TESTGAME_H
