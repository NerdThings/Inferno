cmake_minimum_required (VERSION 3.8)

# Require OpenGL
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
link_libraries( ${OPENGL_LIBRARIES} )

# Add source files
file(GLOB_RECURSE src
    "*.cpp"
	"../Common/*.cpp"
)

# Include SDL Headers
IF (WIN32)

include_directories("../deps/SDL2/include")

ELSE()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

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

ELSE()

target_link_libraries(Inferno.Desktop ${SDL2_LIBRARIES})

ENDIF()



# Copy DLL to output path
add_custom_command(TARGET Inferno.Desktop POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${SDL_DIR}/SDL2.dll ${LIBRARY_OUTPUT_PATH}
)