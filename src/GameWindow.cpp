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

#include <algorithm>
#include <stdexcept>

#include "Inferno/Input/Key.h"
#include "Inferno/Input/Keyboard.h"
#include "Inferno/Input/Mouse.h"
#include "Inferno/Game.h"
#include "Inferno/GameWindow.h"
#include "Inferno/Point.h"
#include "Inferno/Rectangle.h"

namespace Inferno {

#ifdef SDL
    //SDL KeyConverter, it converts an SDL keycode to our key enum
    Input::Key to_key(int key = 0) {
        switch (key) {
            case 8 : return Input::Backspace;
            case 9 : return Input::Tab;
            case 13 : return Input::Enter;
            case 27 : return Input::Escape;
            case 32 : return Input::Space;
            case 39 : return Input::OemQuotes;
            case 43 : return Input::Add;
            case 44 : return Input::OemComma;
            case 45 : return Input::OemMinus;
            case 46 : return Input::OemPeriod;
            case 47 : return Input::OemQuestion;
            case 48 : return Input::D0;
            case 49 : return Input::D1;
            case 50 : return Input::D2;
            case 51 : return Input::D3;
            case 52 : return Input::D4;
            case 53 : return Input::D5;
            case 54 : return Input::D6;
            case 55 : return Input::D7;
            case 56 : return Input::D8;
            case 57 : return Input::D9;
            case 59 : return Input::OemSemicolon;
            case 60 : return Input::OemBackslash;
            case 61 : return Input::OemPlus;
            case 91 : return Input::OemOpenBrackets;
            case 92 : return Input::OemPipe;
            case 93 : return Input::OemCloseBrackets;
            case 96 : return Input::OemTilde;
            case 97 : return Input::A;
            case 98 : return Input::B;
            case 99 : return Input::C;
            case 100 : return Input::D;
            case 101 : return Input::E;
            case 102 : return Input::F;
            case 103 : return Input::G;
            case 104 : return Input::H;
            case 105 : return Input::I;
            case 106 : return Input::J;
            case 107 : return Input::K;
            case 108 : return Input::L;
            case 109 : return Input::M;
            case 110 : return Input::N;
            case 111 : return Input::O;
            case 112 : return Input::P;
            case 113 : return Input::Q;
            case 114 : return Input::R;
            case 115 : return Input::S;
            case 116 : return Input::T;
            case 117 : return Input::U;
            case 118 : return Input::V;
            case 119 : return Input::W;
            case 120 : return Input::X;
            case 121 : return Input::Y;
            case 122 : return Input::Z;
            case 127 : return Input::Delete;
            case 1073741881 : return Input::CapsLock;
            case 1073741882 : return Input::F1;
            case 1073741883 : return Input::F2;
            case 1073741884 : return Input::F3;
            case 1073741885 : return Input::F4;
            case 1073741886 : return Input::F5;
            case 1073741887 : return Input::F6;
            case 1073741888 : return Input::F7;
            case 1073741889 : return Input::F8;
            case 1073741890 : return Input::F9;
            case 1073741891 : return Input::F10;
            case 1073741892 : return Input::F11;
            case 1073741893 : return Input::F12;
            case 1073741894 : return Input::PrintScreen;
            case 1073741895 : return Input::Scroll;
            case 1073741896 : return Input::Pause;
            case 1073741897 : return Input::Insert;
            case 1073741898 : return Input::Home;
            case 1073741899 : return Input::PageUp;
            case 1073741901 : return Input::End;
            case 1073741902 : return Input::PageDown;
            case 1073741903 : return Input::Right;
            case 1073741904 : return Input::Left;
            case 1073741905 : return Input::Down;
            case 1073741906 : return Input::Up;
            case 1073741907 : return Input::NumLock;
            case 1073741908 : return Input::Divide;
            case 1073741909 : return Input::Multiply;
            case 1073741910 : return Input::Subtract;
            case 1073741911 : return Input::Add;
            case 1073741912 : return Input::Enter;
            case 1073741913 : return Input::NumPad1;
            case 1073741914 : return Input::NumPad2;
            case 1073741915 : return Input::NumPad3;
            case 1073741916 : return Input::NumPad4;
            case 1073741917 : return Input::NumPad5;
            case 1073741918 : return Input::NumPad6;
            case 1073741919 : return Input::NumPad7;
            case 1073741920 : return Input::NumPad8;
            case 1073741921 : return Input::NumPad9;
            case 1073741922 : return Input::NumPad0;
            case 1073741923 : return Input::Decimal;
            case 1073741925 : return Input::Apps;
            case 1073741928 : return Input::F13;
            case 1073741929 : return Input::F14;
            case 1073741930 : return Input::F15;
            case 1073741931 : return Input::F16;
            case 1073741932 : return Input::F17;
            case 1073741933 : return Input::F18;
            case 1073741934 : return Input::F19;
            case 1073741935 : return Input::F20;
            case 1073741936 : return Input::F21;
            case 1073741937 : return Input::F22;
            case 1073741938 : return Input::F23;
            case 1073741939 : return Input::F24;
            case 1073741951 : return Input::VolumeMute;
            case 1073741952 : return Input::VolumeUp;
            case 1073741953 : return Input::VolumeDown;
            case 1073742040 : return Input::OemClear;
            case 1073742044 : return Input::Decimal;
            case 1073742048 : return Input::LeftControl;
            case 1073742049 : return Input::LeftShift;
            case 1073742050 : return Input::LeftAlt;
            case 1073742051 : return Input::LeftWindows;
            case 1073742052 : return Input::RightControl;
            case 1073742053 : return Input::RightShift;
            case 1073742054 : return Input::RightAlt;
            case 1073742055 : return Input::RightWindows;
            case 1073742082 : return Input::MediaNextTrack;
            case 1073742083 : return Input::MediaPreviousTrack;
            case 1073742084 : return Input::MediaStop;
            case 1073742085 : return Input::MediaPlayPause;
            case 1073742086 : return Input::VolumeMute;
            case 1073742087 : return Input::SelectMedia;
            case 1073742089 : return Input::LaunchMail;
            case 1073742092 : return Input::BrowserSearch;
            case 1073742093 : return Input::BrowserHome;
            case 1073742094 : return Input::BrowserBack;
            case 1073742095 : return Input::BrowserForward;
            case 1073742096 : return Input::BrowserStop;
            case 1073742097 : return Input::BrowserRefresh;
            case 1073742098 : return Input::BrowserFavorites;
            case 1073742106 : return Input::Sleep;
        }
        
        return Input::None;
    }
#endif
    
    //Constructors
    
    GameWindow::GameWindow(Game* parent_game, std::string title, int width, int height) : _parent_game(parent_game) {
#ifdef SDL
        //SDL Init
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
            throw std::runtime_error("Failed to init SDL.");
        
        //Create window
        _sdl_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        
        //Check window was created
        if (_sdl_window == nullptr)
            throw std::runtime_error("Failed to create window.");
        
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
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
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
        Input::Key k;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                return false;
            } else if (e.type == SDL_MOUSEWHEEL) {
                Input::Mouse::internal_scroll_x = e.wheel.x * 120;
                Input::Mouse::internal_scroll_y = e.wheel.y * 120;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    Input::Mouse::internal_left = true;
                } else if (e.button.button == SDL_BUTTON_MIDDLE) {
                    Input::Mouse::internal_middle = true;
                } else if (e.button.button == SDL_BUTTON_RIGHT) {
                    Input::Mouse::internal_right = true;
                } else if (e.button.button == SDL_BUTTON_X1) {
                    Input::Mouse::internal_x1 = true;
                } else if (e.button.button == SDL_BUTTON_X2) {
                    Input::Mouse::internal_x2 = true;
                }
            } else if (e.type == SDL_MOUSEBUTTONUP) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    Input::Mouse::internal_left = false;
                } else if (e.button.button == SDL_BUTTON_MIDDLE) {
                    Input::Mouse::internal_middle = false;
                } else if (e.button.button == SDL_BUTTON_RIGHT) {
                    Input::Mouse::internal_right = false;
                } else if (e.button.button == SDL_BUTTON_X1) {
                    Input::Mouse::internal_x1 = false;
                } else if (e.button.button == SDL_BUTTON_X2) {
                    Input::Mouse::internal_x2 = false;
                }
            } else if (e.type == SDL_MOUSEMOTION) {
                Input::Mouse::internal_x = e.motion.x;
                Input::Mouse::internal_y = e.motion.y;
            } else if (e.type == SDL_KEYDOWN) {
                k = to_key(e.key.keysym.sym);
                if (std::find(Input::Keyboard::internal_keys.begin(), Input::Keyboard::internal_keys.end(), k) == Input::Keyboard::internal_keys.end())
                    Input::Keyboard::internal_keys.emplace_back(k);
            } else if (e.type == SDL_KEYUP) {
                k = to_key(e.key.keysym.sym);
                Input::Keyboard::internal_keys.erase(std::remove(Input::Keyboard::internal_keys.begin(), Input::Keyboard::internal_keys.end(), k), Input::Keyboard::internal_keys.end());
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
    
    void GameWindow::set_title(std::string title) {
#ifdef SDL
        SDL_SetWindowTitle(_sdl_window, title.c_str());
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