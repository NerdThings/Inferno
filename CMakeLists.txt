cmake_minimum_required (VERSION 3.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

project ("Inferno")

# Set build directory
set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)

# Add sub projects
add_subdirectory("Inferno.Desktop")
add_subdirectory ("Inferno.Desktop.Tests")
