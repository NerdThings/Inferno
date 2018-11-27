//
// Created by Reece Mackie on 20/11/18.
//

#include <cmath>

#include <Inferno/Input/Mouse.h>

#include "TestWall.h"

float rot = 0;

TestWall::TestWall(Inferno::Scene *parent_scene, Inferno::Vector2 position) : Instance(parent_scene, position, 0, false, true) {
    set_width(32);
    set_height(32);
}

void TestWall::draw(Inferno::Graphics::Renderer *renderer) {
    Inferno::Input::MouseState s = Inferno::Input::Mouse::get_state(parent_scene->parent_game);
    if (s.left_button == Inferno::Input::Pressed)
        rot += 0.05f;
    
    renderer->draw_rectangle(get_bounds(), Inferno::Graphics::Color::pink, false, 1, 0, rot, Inferno::Vector2(16, 16));
    renderer->draw_circle(get_position() + Inferno::Vector2(16, 16), 5, Inferno::Graphics::Color::black, 0, rot, false, 2);
}