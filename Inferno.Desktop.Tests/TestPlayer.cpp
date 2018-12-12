//
// Created by Reece Mackie on 19/11/18.
//

#include "TestPlayer.h"

#include <cmath>
#include <Inferno/MathHelper.h>

#include "Inferno/Content/ContentLoader.h"
#include "Inferno/Graphics/Color.h"
#include "Inferno/Input/Keyboard.h"
#include "Inferno/Physics/CircleCollider.h"
#include "Inferno/Physics/RectangleCollider.h"
#include "Inferno/Game.h"
#include "Inferno/Scene.h"
#include "TestWall.h"

#include "Inferno/Events/EventHandler.h"

class TestAction : public Inferno::Events::Action<> {
public:
    void invoke() override {
        //exit(0);
    }
};

Inferno::Events::EventHandler<TestAction> h;

Inferno::Physics::CircleCollider* test;

TestPlayer::TestPlayer(Inferno::Scene* parent_scene) : Instance(parent_scene, Inferno::Vector2(0, 0), 0, true, true) {
    std::string working_dir = Inferno::Content::ContentLoader::get_working_directory();
    Inferno::Graphics::Texture2D* texture = Inferno::Content::ContentLoader::load_texture(working_dir + "/Content/Test_Sprite.png");
    sprite = new Inferno::Graphics::Sprite(texture, Inferno::Vector2(8, 8), 16, 16, 10);
    //rotation = 1.5f;
    //rotation_origin = Inferno::Vector2(8, 8);
    
    h.subscribe(new TestAction());
    
    //Create collider
    collider = new Inferno::Physics::RectangleCollider(this);
    collider->colliding_instance_type = "wall";
    
    test = new Inferno::Physics::CircleCollider(this);
    test->colliding_instance_type = "wall";
    test->circle = Inferno::Circle(get_position(), 32);
}

void TestPlayer::update() {
    //Reset velocity
    velocity = Inferno::Vector2(0, 0);
    
    //Get keyboard state
    auto s = Inferno::Input::Keyboard::get_state();
    
    //Update test collider
    test->circle = Inferno::Circle(get_position(), 32);

#define MOVE_SPEED 1
    
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
        h.invoke();
    }
    
    if (collider->check_collisions(Inferno::Vector2(get_next_position().x, get_position().y))) {
        while (collider->check_collisions(Inferno::Vector2(Inferno::Vector2(get_position().x + Inferno::MathHelper::sign(velocity.x), get_position().y)))) {
            set_position(Inferno::Vector2(get_position().x - Inferno::MathHelper::sign(velocity.x), get_position().y));
        }
        velocity.x = 0;
    }
    
    if (collider->check_collisions(Inferno::Vector2(get_position().x, get_next_position().y))) {
        while (collider->check_collisions(Inferno::Vector2(Inferno::Vector2(get_position().x, get_position().y + Inferno::MathHelper::sign(velocity.y))))) {
            set_position(Inferno::Vector2(get_position().x, get_position().y - Inferno::MathHelper::sign(velocity.y)));
        }
        velocity.y = 0;
    }
    
    if (collider->check_collisions())
        bool hi = false;
}

void TestPlayer::draw(Inferno::Graphics::Renderer *renderer) {
    renderer->draw_rectangle(get_bounds(), Inferno::Graphics::Color::orange, false, 1, 0, 1.5f, Inferno::Vector2(get_bounds().width / 2, get_bounds().height / 2));
    
    Inferno::Graphics::Color color = Inferno::Graphics::Color::red;
    
    if (test->check_collisions())
        color = Inferno::Graphics::Color::blue;
    
    renderer->draw_circle(test->circle.centre, test->circle.radius, color, false);
    Instance::draw(renderer);
}