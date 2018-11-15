//
// Created by Reece Mackie on 15/11/18.
//

#include "TestScene.h"

TestScene::TestScene(Inferno::Game* parent_game) : Scene(parent_game, 1024, 768) {}

void TestScene::draw(Inferno::Graphics::Renderer *renderer) {
    if (tmb == nullptr)
        tmb = Inferno::Content::ContentLoader::load_texture(parent_game->graphics_device, "/home/reece/Programs/mc/icon.png");
    
    renderer->draw_rectangle(Inferno::Rectangle(10, 10, 50, 50), Inferno::Graphics::Color(0, 255, 0, 255), 0);
    renderer->draw_texture(tmb, Inferno::Rectangle(60, 60, 144, 144), Inferno::Graphics::Color(255, 255, 255, 255), 0);
}