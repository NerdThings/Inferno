cmake_minimum_required(VERSION 3.6)

#C++17
set (CMAKE_CXX_STANDARD 17)

# Set output directory
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#Project details
project ("Inferno")

# OpenGL Preference
set(OpenGL_GL_PREFERENCE "GLVND")

# Add sub projects
add_subdirectory("Inferno.Desktop")
add_subdirectory("Inferno.Desktop.Tests")