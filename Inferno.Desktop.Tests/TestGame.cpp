//
// Created by Reece Mackie on 15/11/18.
//

#include "TestGame.h"

TestGame::TestGame() : Inferno::Game(1024, 768) {
    test_scene = new TestScene(this);
    set_scene(test_scene);
}