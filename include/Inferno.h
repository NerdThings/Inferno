#pragma once

//This file contains all Inferno definitions
#ifndef INFERNO_API

//Define version numbers
#define INFERNO_MAJOR = 1;
#define INFERNO_MINOR = 0;

#ifdef _WIN32
#  ifdef INFERNO_API_EXPORTS
#    define INFERNO_API __declspec(dllexport)
#  else
#    define INFERNO_API __declspec(dllimport)
#  endif
#else
#  define INFERNO_API
#endif

#endif