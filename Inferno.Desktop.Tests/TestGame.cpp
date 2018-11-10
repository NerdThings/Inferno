#include "TestGame.h"
#include "Game.h"
#include "Graphics/Renderer.h"
#include "Graphics/Color.h"
#include "Rectangle.h"

using namespace Inferno;
using namespace Graphics;

TestGame::TestGame() : Game(640, 480, "Inferno Test Game", 30, false)
{
}

void TestGame::update() {

}

void TestGame::draw() {
    _renderer->begin(nullptr);
    _renderer->draw_rectangle(new Rectangle(0, 0, 100, 100), new Color(1, 1, 1, 0), 1);
    _renderer->end();
}