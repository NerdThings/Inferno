//
// Created by Reece Mackie on 15/11/18.
//

#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/GameWindow.h"

#include "TestGame.h"

TestGame::TestGame() : Inferno::Game(1024, 768, "Created with Inferno", 120) {
    game_window->resizable(true);
    game_window->set_v_sync(true);
    test_scene = new TestScene(this);
    set_scene(test_scene);
    
    clear_color = Inferno::Graphics::Color::gray;
}