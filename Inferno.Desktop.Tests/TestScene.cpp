//
// Created by reece on 11/11/18.
//

#include "TestScene.h"

using namespace Inferno;

TestScene::TestScene(Game* parent_game) : Scene(parent_game, 1024, 768) {

}

void TestScene::loaded() {
    Scene::loaded();
    
    //Center camera on middle of room
    camera.center_on(camera.get_viewport_center());
    
    //TODO: Work out why rotation is bugged.
    //camera.rotation = 6.3;
}

void TestScene::unloaded() {
    Scene::unloaded();
}