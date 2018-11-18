cmake_minimum_required (VERSION 3.6)

# Include shared headers
include_directories("../include")

# Load source
file(GLOB src
    "*.h"
    "*.cpp"
)

# Add executable
# add_executable (Inferno.Desktop.Tests WIN32 ${src})
add_executable (Inferno.Desktop.Tests ${src})

# Link Inferno.Desktop
target_link_libraries(Inferno.Desktop.Tests Inferno.Desktop)

# Copy content
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Content DESTINATION ${CMAKE_CURRENT_BINARY_DIR})