//
// Created by Reece Mackie on 19/11/18.
//

#include "TestPlayer.h"

#include <cmath>
#include <Inferno/MathHelper.h>

#include "Inferno/Content/ContentLoader.h"
#include "Inferno/Graphics/Color.h"
#include "Inferno/Input/Keyboard.h"
#include "Inferno/Game.h"
#include "Inferno/Scene.h"
#include "TestWall.h"

TestPlayer::TestPlayer(Inferno::Scene* parent_scene) : Instance(parent_scene, Inferno::Vector2(0, 0), 0, true, true) {
    std::string working_dir = Inferno::Content::ContentLoader::get_working_directory();
    Inferno::Graphics::Texture2D* texture = Inferno::Content::ContentLoader::load_texture(working_dir + "/Content/Test_Sprite.png");
    sprite = new Inferno::Graphics::Sprite(texture, Inferno::Vector2(0, 0), 16, 16, 10);
}

void TestPlayer::update() {
    //Reset velocity
    velocity = Inferno::Vector2(0, 0);
    
    //Get keyboard state
    auto s = Inferno::Input::Keyboard::get_state();

#define MOVE_SPEED 2
    
    //Move logic
    if (s.is_key_down(Inferno::Input::W)) {
        velocity.y -= MOVE_SPEED;
    }
    if (s.is_key_down(Inferno::Input::S)) {
        velocity.y += MOVE_SPEED;
    }
    if (s.is_key_down(Inferno::Input::A)) {
        velocity.x -= MOVE_SPEED;
    }
    if (s.is_key_down(Inferno::Input::D)) {
        velocity.x += MOVE_SPEED;
    }
    
    if (colliding<TestWall>(Inferno::Vector2(get_next_position().x, get_position().y))) {
        while (colliding<TestWall>(Inferno::Vector2(Inferno::Vector2(get_position().x + Inferno::MathHelper::sign(velocity.x), get_position().y)))) {
            set_position(Inferno::Vector2(get_position().x - Inferno::MathHelper::sign(velocity.x), get_position().y));
        }
        velocity.x = 0;
    }
    
    if (colliding<TestWall>(Inferno::Vector2(get_position().x, get_next_position().y))) {
        while (colliding<TestWall>(Inferno::Vector2(Inferno::Vector2(get_position().x, get_position().y + Inferno::MathHelper::sign(velocity.y))))) {
            set_position(Inferno::Vector2(get_position().x, get_position().y - Inferno::MathHelper::sign(velocity.y)));
        }
        velocity.y = 0;
    }
}

void TestPlayer::draw(Inferno::Graphics::Renderer *renderer) {
    renderer->draw_rectangle(get_bounds(), Inferno::Graphics::Color::orange, 1, false, 1);
    Instance::draw(renderer);
}