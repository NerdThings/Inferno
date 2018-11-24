//
// Created by Reece Mackie on 15/11/18.
//

#include "TestScene.h"

#include "Graphics/Glyph.h"
#include "Graphics/GraphicsDevice.h"
#include "Input/Keyboard.h"
#include "Input/KeyboardState.h"
#include "Input/Mouse.h"
#include "Input/MouseState.h"
#include "Vector3.h"
#include "TestWall.h"

TestScene::TestScene(Inferno::Game* parent_game) : Scene(parent_game, 1024, 768) {

}

void TestScene::draw(Inferno::Graphics::Renderer *renderer) {
    Inferno::Input::MouseState s = Inferno::Input::Mouse::get_state(parent_game, nullptr);
    Inferno::Input::KeyboardState ks = Inferno::Input::Keyboard::get_state();
    
    Inferno::Graphics::Color c;
    
    if (s.left_button == Inferno::Input::Pressed) {
        c = Inferno::Graphics::Color(0.5f, 1.0f, 1.0f, 1.0f);
    } else if (ks.is_key_down(Inferno::Input::Space)) {
        c = Inferno::Graphics::Color(1.0f, 1.0f, 0.5f, 1.0f);
    } else {
        c = Inferno::Graphics::Color(1.0f, 0.5f, 1.0f, 1.0f);
    }
    
    //renderer->draw_rectangle(Inferno::Rectangle(s.x, s.y, 50, 50), c, 0, true, 0);
    
    renderer->draw_circle(Inferno::Vector2(s.x, s.y), 40, c, 0, false, 2, 48);
    
    renderer->draw_text("Hello World.\nThis is super cool!", Inferno::Vector2(60, 60), fnt, Inferno::Graphics::Color(0, 0, 0, 255), 0);
    
    Scene::draw(renderer);
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