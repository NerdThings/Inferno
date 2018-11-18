cmake_minimum_required(VERSION 3.6)

#C++11
set (CMAKE_CXX_STANDARD 17)

#Project details
project ("Inferno")

# OpenGL Preference
set(OpenGL_GL_PREFERENCE "GLVND")

# Add sub projects
add_subdirectory("Inferno.Desktop")
add_subdirectory("Inferno.Desktop.Tests")