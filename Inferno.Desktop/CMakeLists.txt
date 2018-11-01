# CMakeList.txt : CMake project for TestCMakeDll, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
link_libraries( ${OPENGL_LIBRARIES} )

# Add source to this project's executable.

file(GLOB src
    "*.h"
    "*.cpp"
	"../Common/*.cpp"
)

include_directories("../SDL2/include")
include_directories("../include")

add_library ("Inferno.Desktop" SHARED ${src})
target_compile_definitions("Inferno.Desktop" PRIVATE SDL=1 OPENGL=1 INFERNO_API_EXPORTS=1)
target_link_libraries("Inferno.Desktop" ../../SDL2/lib/SDL2 ../../SDL2/lib/SDL2main)

add_custom_command(TARGET "Inferno.Desktop" POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/lib/SDL2.dll ${LIBRARY_OUTPUT_PATH}
)