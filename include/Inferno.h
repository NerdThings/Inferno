//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_INFERNO_H
#define INFERNO_INFERNO_H

//Define DLL Exports
#ifdef _WIN32
#ifdef INFERNO_API_EXPORTS
#define INFERNO_API _declspec(dllexport)
#else
#define INFERNO_API _declspec(dllimport)
#endif
#else
#define INFERNO_API
#endif

//Define game entrypoint
#ifdef _WIN32
//Include windows
#include <windows.h>
#define GAME_ENTRY int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
#else
#define GAME_ENTRY int main()
#endif

#endif //INFERNO_INFERNO_H