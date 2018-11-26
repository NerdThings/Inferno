//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_TESTSCENE_H
#define INFERNO_TESTSCENE_H

#include "Inferno/Content/ContentLoader.h"
#include "Inferno/Graphics/Camera.h"
#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/Font.h"
#include "Inferno/Graphics/Renderer.h"
#include "Inferno/Graphics/Sprite.h"
#include "Inferno/Graphics/Texture2D.h"
#include "Inferno/Game.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Scene.h"
#include "Inferno/Vector2.h"
#include "TestPlayer.h"

class TestScene : public Inferno::Scene {
    Inferno::Graphics::Sprite* tmb = nullptr;
    TestPlayer* player;
    Inferno::Graphics::Font fnt;
    Inferno::Graphics::Camera camera;
public:
    explicit TestScene(Inferno::Game* parent_game);
    void draw(Inferno::Graphics::Renderer* renderer) override;
	void update() override;
	void loaded() override;
	void unloaded() override;
};


#endif //INFERNO_TESTSCENE_H
