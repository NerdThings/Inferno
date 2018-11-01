cmake_minimum_required (VERSION 3.8)

include_directories( "../include" )

file(GLOB src
    "*.h"
    "*.cpp"
)

add_executable (InfernoDesktopTests ${src})
target_link_libraries(InfernoDesktopTests "Inferno.Desktop")