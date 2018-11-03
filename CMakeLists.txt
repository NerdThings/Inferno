cmake_minimum_required (VERSION 3.8)

project ("Inferno")

# Set build directory
set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)

# Add sub projects
add_subdirectory("Inferno.Desktop")
add_subdirectory ("Inferno.Desktop.Tests")
