# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("TestCMakeDll")

set(dir ${CMAKE_CURRENT_SOURCE_DIR}/Build/)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)

set(SDL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2)

# Include sub-projects.
add_subdirectory("Inferno.Desktop")
add_subdirectory ("Inferno.Desktop.Tests")
