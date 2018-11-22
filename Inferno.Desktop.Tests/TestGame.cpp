//
// Created by Reece Mackie on 15/11/18.
//

#include "Graphics/GraphicsDevice.h"
#include "GameWindow.h"

#include "TestGame.h"

TestGame::TestGame() : Inferno::Game(1024, 768, "Created with Inferno", 120) {
    game_window->resizable(true);
    game_window->set_v_sync(true);
    test_scene = new TestScene(this);
    set_scene(test_scene);
    
    const char* vertex =  "#version 330\n"
                                       "attribute vec3 inf_position;\n"
                                       "attribute vec4 inf_color;\n"
                                       "attribute vec2 inf_texcoord;\n"
                                       "uniform mat4 inf_matrix;\n"
                                       "out vec4 fragColor;\n"
                                       "out vec2 texCoord;\n"
                                       "void main() {\n"
                                       "    gl_Position = inf_matrix * vec4(inf_position, 1);\n"
                                       "    fragColor = inf_color;\n"
                                       "    texCoord = inf_texcoord;\n"
                                       "}";
    
    test_vshader = new Inferno::Graphics::Shader(Inferno::Graphics::Vertex);
    test_vshader->set_source(vertex, Inferno::Graphics::GLSL);
    test_vshader->compile();
    
    const char* fragment = "#version 330\n"
                                        "in vec4 fragColor;\n"
                                        "in vec2 texCoord;\n"
                                        "out vec4 color;\n"
                                        "uniform sampler2D inf_texture;\n"
                                        "void main() {\n"
                                        "   color = texture(inf_texture, texCoord) * fragColor;\n"
                                        "}\n";
    
    test_fshader = new Inferno::Graphics::Shader(Inferno::Graphics::Fragment);
    test_fshader->set_source(fragment, Inferno::Graphics::GLSL);
    test_fshader->compile();
    
    graphics_device->attach_shader(test_fshader);
    graphics_device->attach_shader(test_vshader);
    
    graphics_device->clear(Inferno::Graphics::Color(0, 0, 0, 0));
}