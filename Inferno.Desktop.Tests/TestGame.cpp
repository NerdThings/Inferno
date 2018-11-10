#include "TestGame.h"
#include "Game.h"
#include "Graphics/Renderer.h"
#include "Graphics/Color.h"
#include "Rectangle.h"

using namespace Inferno;
using namespace Graphics;

TestGame::TestGame() : Game(640, 480, "Inferno Test Game", 30, false) {
}

void TestGame::update() {

}

void TestGame::draw() {
    Game::draw();
}