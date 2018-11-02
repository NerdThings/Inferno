cmake_minimum_required (VERSION 3.8)

# Include shared headers
include_directories( "../include" )

# Load source
file(GLOB src
    "*.h"
    "*.cpp"
)

# Add executable
add_executable (InfernoDesktopTests ${src})

# Link Inferno.Desktop
target_link_libraries(InfernoDesktopTests InfernoDesktop)