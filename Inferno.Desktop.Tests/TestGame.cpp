#include "TestGame.h"
#include "Game.h"
#include "Graphics/Renderer.h"
#include "Graphics/Color.h"
#include "Rectangle.h"
#include "GameWindow.h"

using namespace Inferno;
using namespace Graphics;

TestGame::TestGame() : Game(1280, 768, "Inferno Test Game", 30, false) {
    _game_window->set_title("Hellooooo");
    _game_window->set_cursor(true);
    _game_window->resizable(true);
    //_game_window->set_fullscreen(true);
}

void TestGame::update() {

}

void TestGame::draw() {
    Game::draw();
    _renderer->begin();
    _renderer->draw_rectangle(Rectangle(0, 0, 100, 100), Color(0.4f, 0.2f, 0.3f, 0.6f), 0);
    _renderer->end();
}