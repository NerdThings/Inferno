#include "TestGame.h"
#include "Game.h"
#include "Graphics/Renderer.h"
#include "Graphics/Color.h"
#include "Rectangle.h"
#include "GameWindow.h"

#include "TestScene.h"

#include "Content/ContentLoader.h"

using namespace Inferno;
using namespace Graphics;
using namespace Content;

TestScene scene = nullptr;
Texture2D* test = nullptr;

TestGame::TestGame() : Game(1280, 768, "Inferno Test Game", 30, false) {
    game_window->set_cursor(true);
    game_window->resizable(true);
    //_game_window->set_fullscreen(true);
    
    scene = TestScene(this);
    set_scene(&scene);
    
    Texture2D tmb = ContentLoader::load_texture(_graphics_device, "/home/reece/Programs/mc/icon.png");
    //test = &tmb;
    
    Color* data = new Color[2*2];
    data[0] = Color(255, 0, 255, 255);
    data[1] = Color(255, 255, 0, 255);
    data[2] = Color(0, 255, 255, 255);
    data[3] = Color(255, 255, 255, 255);
    
    //test = new Texture2D(_graphics_device, 2, 2, data);
    
    auto d = tmb.get_data();
    
    test = new Texture2D(_graphics_device, tmb.get_width(), tmb.get_height(), tmb.get_data());
    
    //int a = test->width;
    //int b = test->height;
    
    printf("HI");
}

void TestGame::update() {

}

void TestGame::draw() {
    Game::draw();
    //_renderer->begin();
    _renderer->draw_rectangle(Rectangle(0, 0, 100, 100), Color(0.4f, 0.2f, 0.3f, 0.6f), 0);
    
    _renderer->draw_texture(test, Vector2(100, 100), Color(1.0f, 1.0f, 1.0f, 1.0f), 0);
    
    //_renderer->end();
    
    if (_current_scene != nullptr)
        _current_scene->draw(_renderer);
}