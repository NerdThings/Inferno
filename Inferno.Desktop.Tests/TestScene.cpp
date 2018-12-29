//
// Created by Reece Mackie on 15/11/18.
//

#define _USE_MATH_DEFINES
#include <cmath>

#include "TestScene.h"

#include "Inferno/Events/Action.h"
#include "Inferno/Events/EventHandler.h"
#include "Inferno/Graphics/Glyph.h"
#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Input/Keyboard.h"
#include "Inferno/Input/KeyboardState.h"
#include "Inferno/Input/Mouse.h"
#include "Inferno/Input/MouseState.h"
#include "Inferno/UI/Control.h"
#include "Inferno/Vector3.h"
#include "TestWall.h"

UI::Control* test_control = nullptr;

class ControlAction : public Events::Action<Events::ActionArgs> {
public:
    void invoke() override {
        exit(0);
    }
};

TestScene::TestScene(Game* parent_game) : Scene(parent_game, 1024, 768), camera(Graphics::Camera(this, 2.0f)) {
    background = new Graphics::Sprite(new Graphics::Texture2D(1024, 768, Graphics::Color::white), Vector2(0, 0));
    camera.center_on(Vector2(50, 50));
    
    background_depth = -99;
    
    test_control = new UI::Control(parent_game, Vector2(50, 50));
    test_control->onclick.subscribe(new ControlAction());
    test_control->back_color = Graphics::Color::blue;
    test_control->width = 100;
    test_control->height = 100;
}

Line a = Line({10, 10}, {100, 10});
Line b = Line({100, 10}, {100, 100});

bool intersect = false;

void TestScene::draw(Graphics::Renderer *renderer) {
    parent_game->graphics_device->push_view_matrix();
    parent_game->graphics_device->set_view_matrix(camera.get_translation_matrix());
    Input::MouseState s = Input::Mouse::get_state(parent_game);
    Input::KeyboardState ks = Input::Keyboard::get_state();
    
    Graphics::Color c;
    
    //renderer->draw_text("Hello World.\nThis is super cool!", Vector2(60, 60), fnt, Graphics::Color::black, 0, 0);
    
    //renderer->draw_line(Line(Vector2(0, 0), Vector2(50, 50)), Graphics::Color::red, 1, 0, M_PI * 0.25f);
    
    //renderer->draw_rectangle(Rectangle(s.x, s.y, 50, 50), c, true, 1, 0, 0);
    
    //renderer->draw_circle(Circle(Vector2(s.x, s.y), 40), Graphics::Color::red, 0, 1.5f, false, 2, 48);
    
    //TEST
    
    Graphics::Color ac = Graphics::Color::blue;
    Graphics::Color bc = Graphics::Color::green;
    
    if (intersect) {
        ac = Graphics::Color::red;
        bc = Graphics::Color::red;
    }
    
    //renderer->draw_line(a, ac);
    //renderer->draw_line(b, bc);
    
    Scene::draw(renderer);
    parent_game->graphics_device->pop_view_matrix();
    //test_control->update();
    //test_control->draw(renderer);
}

void TestScene::update() {
    
    Input::MouseState s = Input::Mouse::get_state(parent_game);
    
    b = Line(Vector2(s.x, s.y), Vector2(s.x, s.y + 90));
    
    intersect = a.intersects(b);
    
    Scene::update();

    camera.center_on(player->get_position());
    safezone = Inferno::Rectangle(player->get_position().x - 150.0f, player->get_position().y - 150.0f, 300.0f, 300.0f);
}

void TestScene::loaded() {
    safezone_enabled = true;
    draw_outside_safezone = false;

    player = new TestPlayer(this);
    add_instance(player);
    
    for (int i = 0; i < 1000; i++) { //500 = current max tested before major performance drop
        add_instance(new TestWall(this, Vector2(i * 128, 20)));
    }
    
    std::string working_dir = Content::ContentLoader::get_working_directory();
    fnt = Content::ContentLoader::load_font(working_dir + "/Content/Roboto-Black.ttf", 36);
}

void TestScene::unloaded() {
    remove_instance(player);
    delete player;
}