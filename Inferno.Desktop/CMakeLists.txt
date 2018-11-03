cmake_minimum_required (VERSION 3.8)

# Require OpenGL
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
link_libraries( ${OPENGL_LIBRARIES} )

# Find SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/")

# Add source files
file(GLOB_RECURSE src
    "*.cpp"
	"../Common/*.cpp"
)

# Include SDL Headers
include_directories("../deps/SDL2/include")

# Check SDL is on the UNIX system
IF (UNIX)

find_package(SDL2 REQUIRED)

ENDIF()

# Include Inferno shared headers
include_directories("../include")

# Add Library
add_library (Inferno.Desktop SHARED ${src})

# Set definitions
target_compile_definitions(Inferno.Desktop PRIVATE SDL=1 OPENGL=1 INFERNO_API_EXPORTS=1)

# Link SDL

IF (WIN32)

# Set SDL Directory
set (SDL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../deps/SDL2/lib)
target_link_libraries(Inferno.Desktop ${SDL_DIR}/SDL2.lib ${SDL_DIR}/SDL2main.lib)

# Copy DLL to output path
add_custom_command(TARGET Inferno.Desktop POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${SDL_DIR}/SDL2.dll ${LIBRARY_OUTPUT_PATH}
)

ELSE()

target_link_libraries(Inferno.Desktop ${SDL2_LIBRARIES})

ENDIF()
