cmake_minimum_required (VERSION 3.6)

# Require OpenGL
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

# Find SDL2
IF (UNIX)

# Search for UNIX SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/")

ELSE()

# Add Windows SDL2
set (SDL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../deps/SDL2/lib")

set(SDL2_LIBRARY"${SDL_DIR}/SDL2.lib" "${SDL_DIR}/SDL2main.lib")

ENDIF()

# Add source files
file(GLOB_RECURSE src
	"../src/*.cpp"
	# glad source
	"../deps/glad/src/glad.c"
)

# Include SDL Headers
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../deps/SDL2/include")

# Include glad headers
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../deps/glad/include")

# Check SDL is on the UNIX system
IF (UNIX)

find_package(SDL2 REQUIRED)

ENDIF()

# Include Inferno shared headers
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include")

# Add Library
add_library (Inferno.Desktop SHARED ${src})

# Remove any prefixes
SET_TARGET_PROPERTIES(Inferno.Desktop PROPERTIES PREFIX "")

# Set definitions
target_compile_definitions(Inferno.Desktop PRIVATE SDL=1 OPENGL=1 INFERNO_API_EXPORTS=1)

# Link SDL
target_link_libraries(Inferno.Desktop ${SDL2_LIBRARY})

# Link OpenGL
target_link_libraries(Inferno.Desktop ${OPENGL_LIBRARIES})

IF (WIN32)

# Copy SDL2 DLL to output path
add_custom_command(TARGET Inferno.Desktop POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${SDL_DIR}/SDL2.dll ${LIBRARY_OUTPUT_PATH}
)

ENDIF()
