//
// Created by Reece Mackie on 20/11/18.
//

#include "TestWall.h"

TestWall::TestWall(Inferno::Scene *parent_scene, Inferno::Vector2 position) : Instance(parent_scene, position, 0, false, true) {
    set_width(32);
    set_height(32);
}

void TestWall::draw(Inferno::Graphics::Renderer *renderer) {
    renderer->draw_rectangle(get_bounds(), Inferno::Graphics::Color::pink, 0, true, 1);
}