cmake_minimum_required (VERSION 3.8)

# Require OpenGL
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
link_libraries( ${OPENGL_LIBRARIES} )

# Add source files
file(GLOB src
    "*.h"
    "*.cpp"
	"../Common/*.cpp"
)

# Include SDL Headers
include_directories("../deps/SDL2/include")

# Include Inferno shared headers
include_directories("../include")

# Add Library
add_library (InfernoDesktop SHARED ${src})

# Set definitions
target_compile_definitions(InfernoDesktop PRIVATE SDL=1 OPENGL=1 INFERNO_API_EXPORTS=1)

# Set SDL Directory
set (SDL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../deps/SDL2/lib)

# Link SDL
target_link_libraries(InfernoDesktop ${SDL_DIR}/SDL2.lib ${SDL_DIR}/SDL2main.lib)

# Copy DLL to output path
add_custom_command(TARGET InfernoDesktop POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${SDL_DIR}/SDL2.dll ${LIBRARY_OUTPUT_PATH}
)