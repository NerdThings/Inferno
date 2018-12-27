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
#include "Inferno/Physics/SpriteCollider.h"
#include "Inferno/Physics/RectangleCollider.h"
#include "Inferno/Game.h"
#include "Inferno/Scene.h"
#include "TestWall.h"

#include "Inferno/Events/EventHandler.h"

class TestAction : public Events::Action<> {
public:
    void invoke() override {
        //exit(0);
    }
};

Events::EventHandler<TestAction> h;

Physics::CircleCollider* test;

TestPlayer::TestPlayer(Scene* parent_scene) : UpdatableInstance(parent_scene, Vector2(0, 0), 0) {
    std::string working_dir = Content::ContentLoader::get_working_directory();
    Graphics::Texture2D* texture = Content::ContentLoader::load_texture(working_dir + "/Content/Test_Sprite.png");
    sprite = new Graphics::Sprite(texture, Vector2(8, 8), 16, 16, 10);
    //rotation = 1.5f;
    //rotation_origin = Vector2(8, 8);
    
    h.subscribe(new TestAction());
    
    //Create collider
    collider = new Physics::RectangleCollider(this);
    //collider = new Physics::SpriteCollider(this);
    
    Graphics::Texture2D* mask = Content::ContentLoader::load_texture(working_dir + "/Content/Test_Mask.png");
    //collider->as<Physics::SpriteCollider>()->sprite = new Graphics::Sprite(mask, Vector2::zero);
    
    collider->colliding_instance_type = "wall";
    
    test = new Physics::CircleCollider(this);
    test->colliding_instance_type = "wall";
    test->circle = Circle(get_position(), 32);
}

bool collision = false;
bool test_collide = false;

void TestPlayer::update() {
    //Reset velocity
    velocity = Vector2(0, 0);
    
    //Get keyboard state
    auto s = Input::Keyboard::get_state();
    
    //Update test collider
    test->circle = Circle(get_position(), 32);
    
    test_collide = test->check_collisions();
    
#define MOVE_SPEED 1
    
    //Move logic
    if (s.is_key_down(Input::W)) {
        velocity.y -= MOVE_SPEED;
    }
    if (s.is_key_down(Input::S)) {
        velocity.y += MOVE_SPEED;
    }
    if (s.is_key_down(Input::A)) {
        velocity.x -= MOVE_SPEED;
    }
    if (s.is_key_down(Input::D)) {
        velocity.x += MOVE_SPEED;
    }
    
    if (collider->check_collisions(Vector2(get_next_position().x, get_position().y))) {
        //while (collider->check_collisions(Vector2(Vector2(get_position().x + MathHelper::sign(velocity.x), get_position().y)))) {
        //    set_position(Vector2(get_position().x - MathHelper::sign(velocity.x), get_position().y));
        //}
        velocity.x = 0;
    }
    
    if (collider->check_collisions(Vector2(get_position().x, get_next_position().y))) {
        //while (collider->check_collisions(Vector2(Vector2(get_position().x, get_position().y + MathHelper::sign(velocity.y))))) {
        //    set_position(Vector2(get_position().x, get_position().y - MathHelper::sign(velocity.y)));
        //}
        velocity.y = 0;
    }
    
    collision = collider->check_collisions(get_next_position());
}

void TestPlayer::draw(Graphics::Renderer *renderer) {
    renderer->draw_rectangle(get_bounds(), Graphics::Color::orange, false, 1, 0, 1.5f, Vector2(get_bounds().width / 2, get_bounds().height / 2));
    
    Graphics::Color color = Graphics::Color::red;
    
    if (test_collide)
        color = Graphics::Color::blue;
    
    renderer->draw_circle(test->circle, color, 0, 0, false, 2);
    Instance::draw(renderer);
}