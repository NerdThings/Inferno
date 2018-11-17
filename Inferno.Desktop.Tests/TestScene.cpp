//
// Created by Reece Mackie on 15/11/18.
//

#include <Input/Mouse.h>
#include "TestScene.h"

#include "Input/Mouse.h"
#include "Input/MouseState.h"
#include "Vector3.h"

TestScene::TestScene(Inferno::Game* parent_game) : Scene(parent_game, 1024, 768) {}

void TestScene::draw(Inferno::Graphics::Renderer *renderer) {
    if (tmb == nullptr) {
        Inferno::Graphics::Texture2D* temp = Inferno::Content::ContentLoader::load_texture(parent_game->graphics_device, "/home/reece/Downloads/logo.png");
        tmb = new Inferno::Graphics::Sprite(temp, Inferno::Vector2(0, 0), 800, 683); //800 = half image width
    }
    
    Inferno::Input::MouseState s = Inferno::Input::Mouse::get_state(parent_game, nullptr);
    
    Inferno::Graphics::Color c;
    
    if (s.left_button == Inferno::Input::Released) {
        c = Inferno::Graphics::Color(0.5f, 1.0f, 1.0f, 1.0f);
    } else {
        c = Inferno::Graphics::Color(1.0f, 0.5f, 1.0f, 1.0f);
    }
    
    renderer->draw_rectangle(Inferno::Rectangle(s.x, s.y, 50, 50), c, 0);
    //renderer->draw_texture(tmb->get_current_texture(), Inferno::Rectangle(60, 60, 800, 683), tmb->get_source_rectangle(), tmb->origin, Inferno::Graphics::Color(255, 255, 255, 255), 0);
    
    tmb->update();
}