//
// Created by Reece Mackie on 15/11/18.
//

#include "TestScene.h"

TestScene::TestScene(Inferno::Game* parent_game) : Scene(parent_game, 1024, 768) {}

void TestScene::draw(Inferno::Graphics::Renderer *renderer) {
    if (tmb == nullptr) {
        Inferno::Graphics::Texture2D* temp = Inferno::Content::ContentLoader::load_texture(parent_game->graphics_device, "/home/reece/Downloads/logo.png");
        tmb = new Inferno::Graphics::Sprite(temp, Inferno::Vector2(0, 0), 800, 683);
    }
    
    renderer->draw_rectangle(Inferno::Rectangle(10, 10, 50, 50), Inferno::Graphics::Color(0, 255, 0, 255), 0);
    renderer->draw_texture(tmb->get_current_texture(), Inferno::Rectangle(60, 60, 800, 683), tmb->get_source_rectangle(), Inferno::Graphics::Color(255, 255, 255, 255), 0);
    
    tmb->update();
}