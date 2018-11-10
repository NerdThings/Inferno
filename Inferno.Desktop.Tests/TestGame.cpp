#include "TestGame.h"
#include "Game.h"
#include "Graphics/Renderer.h"
#include "Graphics/Color.h"
#include "Rectangle.h"
#include "GameWindow.h"

using namespace Inferno;
using namespace Graphics;

TestGame::TestGame() : Game(640, 480, "Inferno Test Game", 30, false) {
    _game_window->set_title("Hellooooo");
    _game_window->set_cursor(true);
    _game_window->resizable(true);
}

void TestGame::update() {

}

void TestGame::draw() {
    Game::draw();
}