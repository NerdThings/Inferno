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

#endif //INFERNO_INFERNO_H