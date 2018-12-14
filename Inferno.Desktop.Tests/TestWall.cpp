//
// Created by Reece Mackie on 20/11/18.
//

#include <cmath>

#include <Inferno/Input/Mouse.h>
#include <Inferno/Physics/RectangleCollider.h>
#include <Inferno/Physics/LineCollider.h>

#include "TestWall.h"

TestWall::TestWall(Inferno::Scene *parent_scene, Inferno::Vector2 position) : Instance(parent_scene, position, 0, false, true) {
    set_width(32);
    set_height(32);
    
    rotation_origin = Inferno::Vector2(16, 16);
    
    //collider = new Inferno::Physics::RectangleCollider(this);
    collider = new Inferno::Physics::LineCollider(this, {});
    
    type = "wall";
}

void TestWall::draw(Inferno::Graphics::Renderer *renderer) {
    
    collider->as<Inferno::Physics::LineCollider>()->lines = get_bounds().lines();
    
    Inferno::Input::MouseState s = Inferno::Input::Mouse::get_state(parent_scene->parent_game);
    if (s.left_button == Inferno::Input::Pressed)
        rotation += 0.05f;
    
    renderer->draw_circle(Inferno::Circle(get_position() + Inferno::Vector2(16, 16), 5), Inferno::Graphics::Color::black, 0, rotation, false, 2);
    
    Inferno::Graphics::Color c = Inferno::Graphics::Color::pink;
    
    if (get_bounds().contains(Inferno::Vector2(s.x, s.y)))
        c = Inferno::Graphics::Color::red;
    
    renderer->draw_rectangle(get_bounds(), c, false, 1, 0);
}