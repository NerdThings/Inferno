//
// Created by Reece Mackie on 15/11/18.
//

#include <cmath>

#include "TestScene.h"

#include "Inferno/Graphics/Glyph.h"
#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Input/Keyboard.h"
#include "Inferno/Input/KeyboardState.h"
#include "Inferno/Input/Mouse.h"
#include "Inferno/Input/MouseState.h"
#include "Inferno/Vector3.h"
#include "TestWall.h"

TestScene::TestScene(Inferno::Game* parent_game) : Scene(parent_game, 1024, 768), camera(Inferno::Graphics::Camera(this, 1.0f)) {
    background = new Inferno::Graphics::Sprite(new Inferno::Graphics::Texture2D(1024, 768, Inferno::Graphics::Color::white), Inferno::Vector2(0, 0));
    camera.center_on(Inferno::Vector2(50, 50));
    
    background_depth = -99;
}

void TestScene::draw(Inferno::Graphics::Renderer *renderer) {
    parent_game->graphics_device->push_view_matrix();
    parent_game->graphics_device->set_view_matrix(camera.get_translation_matrix());
    Inferno::Input::MouseState s = Inferno::Input::Mouse::get_state(parent_game);
    Inferno::Input::KeyboardState ks = Inferno::Input::Keyboard::get_state();
    
    Inferno::Graphics::Color c;
    
    if (s.left_button == Inferno::Input::Pressed) {
        c = Inferno::Graphics::Color(0.5f, 1.0f, 1.0f, 1.0f);
    } else if (ks.is_key_down(Inferno::Input::Space)) {
        c = Inferno::Graphics::Color(1.0f, 1.0f, 0.5f, 1.0f);
    } else {
        c = Inferno::Graphics::Color(1.0f, 0.5f, 1.0f, 1.0f);
    }
    
    renderer->draw_text("Hello World.\nThis is super cool!", Inferno::Vector2(60, 60), fnt, Inferno::Graphics::Color::black, 0, 0);
    
    renderer->draw_line(Inferno::Vector2(0, 0), Inferno::Vector2(50, 50), Inferno::Graphics::Color::red, 1, 0, M_PI * 0.25f);
    
    renderer->draw_rectangle(Inferno::Rectangle(s.x, s.y, 50, 50), c, true, 1, 0, 0);
    
    renderer->draw_circle(Inferno::Vector2(s.x, s.y), 40, Inferno::Graphics::Color::red, 0, 1.5f, false, 2, 48);
    
    
    Scene::draw(renderer);
    parent_game->graphics_device->pop_view_matrix();
}

void TestScene::update() {
    Scene::update();
}

void TestScene::loaded() {
    player = new TestPlayer(this);
    add_instance(player);
    
    add_instance(new TestWall(this, Inferno::Vector2(20, 20)));
    
    std::string working_dir = Inferno::Content::ContentLoader::get_working_directory();
    fnt = Inferno::Content::ContentLoader::load_font(working_dir + "/Content/Roboto-Black.ttf", 36);
}

void TestScene::unloaded() {
    remove_instance(player);
    delete player;
}