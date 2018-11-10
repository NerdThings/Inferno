cmake_minimum_required(VERSION 3.6)

#C++11
set (CMAKE_CXX_STANDARD 11)

#Project details
project ("Inferno")

# Set build directory
set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)

# OpenGL Preference
set(OpenGL_GL_PREFERENCE "GLVND")

# Add sub projects
add_subdirectory("Inferno.Desktop")
add_subdirectory("Inferno.Desktop.Tests")