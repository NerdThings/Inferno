//
// Created by Reece Mackie on 19/11/18.
//

#include "TestPlayer.h"

#include "Content/ContentLoader.h"
#include "Input/Keyboard.h"
#include "Game.h"
#include "Scene.h"

TestPlayer::TestPlayer(Inferno::Scene* parent_scene) : Instance(parent_scene, Inferno::Vector2(0, 0), 0, true, true) {
    std::string working_dir = Inferno::Content::ContentLoader::get_working_directory();
    Inferno::Graphics::Texture2D* texture = Inferno::Content::ContentLoader::load_texture(parent_scene->parent_game->graphics_device, working_dir + "/Content/Test_Sprite.png");
    sprite = new Inferno::Graphics::Sprite(texture, Inferno::Vector2(0, 0), 16, 16, 10);
}

void TestPlayer::update() {
    //Reset velocity
    velocity = Inferno::Vector2(0, 0);
    
    //Get keyboard state
    auto s = Inferno::Input::Keyboard::get_state();
    
    //Move logic
    if (s.is_key_down(Inferno::Input::W)) {
        velocity.y -= 2;
    }
    if (s.is_key_down(Inferno::Input::S)) {
        velocity.y += 2;
    }
    if (s.is_key_down(Inferno::Input::A)) {
        velocity.x -= 2;
    }
    if (s.is_key_down(Inferno::Input::D)) {
        velocity.x += 2;
    }
    
    //Run standard updates
    Instance::update();
}

void TestPlayer::draw(Inferno::Graphics::Renderer *renderer) {
    Instance::draw(renderer);
}