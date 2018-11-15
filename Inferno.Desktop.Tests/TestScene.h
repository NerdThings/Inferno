//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_TESTSCENE_H
#define INFERNO_TESTSCENE_H

#include "Content/ContentLoader.h"
#include "Graphics/Color.h"
#include "Graphics/Renderer.h"
#include "Graphics/Texture2D.h"
#include "Game.h"
#include "Rectangle.h"
#include "Scene.h"

class TestScene : public Inferno::Scene {
    Inferno::Graphics::Texture2D* tmb = nullptr;
public:
    TestScene(Inferno::Game* parent_game);
    void draw(Inferno::Graphics::Renderer* renderer) override;
};


#endif //INFERNO_TESTSCENE_H
