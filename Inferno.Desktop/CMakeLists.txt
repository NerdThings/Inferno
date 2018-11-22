cmake_minimum_required (VERSION 3.6)

# Require OpenGL
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

# Find SDL2
IF (UNIX)

    # Search for UNIX SDL2
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/")

    # Require DevIL
    find_package(DevIL REQUIRED)

    # Require Freetype
    find_package(Freetype REQUIRED)

    # Require harfbuzz
    find_package(Harfbuzz REQUIRED)

ELSE()

    # Add Windows SDL2
    set (SDL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../deps/SDL2/lib")
    set(SDL2_LIBRARY "${SDL_DIR}/SDL2.lib" "${SDL_DIR}/SDL2main.lib")

    # Add Windows DevIL
    set (IL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../deps/DevIL/lib")
    set(IL_LIBRARIES "${IL_DIR}/DevIL.lib")

    # Add Freetype
    set (FREETYPE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../deps/freetype/lib")
    set(FREETYPE_LIBRARIES "${FREETYPE_DIR}/freetype.lib")

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

# Include DevIL Headers
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../deps/DevIL/include")

# Include GZIP
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../deps/gzip/include")

# Include Freetype
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../deps/freetype/include")

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
target_compile_definitions(Inferno.Desktop PRIVATE INFERNO=1 SDL=1 OPENGL=1 INFERNO_API_EXPORTS=1)

# Link stdc++fs
IF (UNIX)
    target_link_libraries(Inferno.Desktop stdc++fs)
ENDIF()

# Link SDL
target_link_libraries(Inferno.Desktop ${SDL2_LIBRARY})

# Link OpenGL
target_link_libraries(Inferno.Desktop ${OPENGL_LIBRARIES})

# Link DevIL
target_link_libraries(Inferno.Desktop ${IL_LIBRARIES})

# Link Freetype
target_link_libraries(Inferno.Desktop ${FREETYPE_LIBRARIES})

# Include Harfbuzz
target_link_libraries(Inferno.Desktop ${HarfBuzz_LIBRARIES})

IF (WIN32)

    # Copy SDL2 DLL to output path )
    file(COPY ${SDL_DIR}/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

    # Copy DevIL DLL to output path
    file(COPY ${IL_DIR}/DevIL.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

ENDIF()

# Copy include folder
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../include DESTINATION ${CMAKE_CURRENT_BINARY_DIR})