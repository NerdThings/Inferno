cmake_minimum_required (VERSION 3.6)

# Include shared headers
include_directories("../include")

# Load source
file(GLOB src
    "*.h"
    "*.cpp"
)

# Add executable
add_executable (Inferno.Desktop.Tests ${src} WIN32)

# Link Inferno.Desktop
target_link_libraries(Inferno.Desktop.Tests Inferno.Desktop)
