#pragma once
#include "Game.h"

using namespace Inferno;

class TestGame : public Game {
public:
	TestGame();
	void update() override;
};