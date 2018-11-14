//
// Created by Reece Mackie on 13/11/18.
//

#include "IL/il.h"
#ifdef OPENGL
#include "glad/glad.h"
#endif
#ifdef SDL
#include "SDL.h"
#endif

#include "Game.h"
#include "GameWindow.h"
#include "Point.h"
#include "Rectangle.h"

namespace Inferno {
    //Constructors
    
    GameWindow::GameWindow(Game* parent_game, const char *title, int width, int height) : _parent_game(parent_game) {
#ifdef SDL
        //SDL Init
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
            throw "Failed to init SDL.";
        
        //Create window
        _sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        
        //Check window was created
        if (_sdl_window == nullptr)
            throw "Failed to create window.";
        
        //Init SDL OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetSwapInterval(0);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_CreateContext(_sdl_window);
#endif
#ifdef OPENGL
        
        //Load glad
        gladLoadGL();
        
        //Set viewport
        glViewport(0, 0, width, height);
        
        //Enables
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#endif
    }
    
    //Deconstructors
    
    GameWindow::~GameWindow() {
        //Detach parent game
        _parent_game = nullptr;
        
#ifdef SDL
        //Destroy window
        SDL_DestroyWindow(_sdl_window);
        _sdl_window = nullptr;
        
        //Quit SDL
        SDL_Quit();
#endif
    }
    
    //Methods
    
    void GameWindow::alt_f4(bool enabled) {
#ifdef SDL
        SDL_SetHint(SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4, enabled ? "0" : "1");
#endif
    }
    
    Rectangle GameWindow::get_bounds() {
        Point pos = get_position();
        Point size = get_size();
        return {pos.x, pos.y, size.x, size.y};
    }
    
    Point GameWindow::get_position() {
#ifdef SDL
        int x,y;
        SDL_GetWindowPosition(_sdl_window, &x, &y);
        return {x, y};
#endif
    }
    
    Point GameWindow::get_size() {
#ifdef SDL
        int w,h;
        SDL_GL_GetDrawableSize(_sdl_window, &w, &h);
        return {w, h};
#endif
    }
    
    void GameWindow::resizable(bool resizable) {
#ifdef SDL
        SDL_SetWindowResizable(_sdl_window, (SDL_bool)resizable);
#endif
    }
    
    bool GameWindow::run_events() {
#ifdef SDL
        //TODO: Mouse, keyboard and resize events
        
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                return false;
            }
        }
#endif
        return true;
    }
    
    void GameWindow::set_bounds(Inferno::Rectangle bounds) {
        set_position({bounds.x, bounds.y});
        set_size({bounds.width, bounds.height});
    }
    
    void GameWindow::set_fullscreen(bool fullscreen) {
#ifdef SDL
        SDL_SetWindowFullscreen(_sdl_window, (SDL_bool)fullscreen);
#endif
    }
    
    void GameWindow::set_position(Inferno::Point position) {
#ifdef SDL
        SDL_SetWindowPosition(_sdl_window, position.x, position.y);
#endif
    }
    
    void GameWindow::set_size(Inferno::Point size) {
#ifdef SDL
        SDL_SetWindowSize(_sdl_window, size.x, size.y);
#endif
    }
    
    void GameWindow::set_title(const char *title) {
#ifdef SDL
        SDL_SetWindowTitle(_sdl_window, title);
#endif
    }
    
    void GameWindow::set_v_sync(bool vsync) {
#ifdef SDL
        SDL_GL_SetSwapInterval(vsync ? 1 : 0);
#endif
    }
    
    void GameWindow::set_cursor(bool visible) {
#ifdef SDL
        SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
#endif
    }
    
    void GameWindow::present() {
#ifdef SDL
        SDL_GL_SwapWindow(_sdl_window);
#endif
    }
}