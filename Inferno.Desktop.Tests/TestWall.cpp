//
// Created by Reece Mackie on 20/11/18.
//

#include <cmath>

#include <Inferno/Input/Mouse.h>
#include <Inferno/Physics/RectangleCollider.h>

#include "TestWall.h"

TestWall::TestWall(Scene *parent_scene, Vector2 position) : Instance(parent_scene, position, 0) {
    set_width(32);
    set_height(32);
    
    rotation_origin = Vector2(16, 16);
    
    collider = new Physics::RectangleCollider(this);
    
    type = "wall";
}

void TestWall::draw(Graphics::Renderer *renderer) {
    //return;
    //Input::MouseState s = Input::Mouse::get_state(parent_scene->parent_game);
    //if (s.left_button == Input::Pressed)
    //    rotation += 0.05f;
    
    //renderer->draw_circle(Circle(get_position() + Vector2(16, 16), 5), Graphics::Color::black, 0, rotation, false, 2);
    
    Graphics::Color c = Graphics::Color::pink;
    
    //if (get_bounds().contains(Vector2(s.x, s.y)))
    //    c = Graphics::Color::red;
    
    renderer->draw_rectangle(get_bounds(), c, true, 1, 0);
}