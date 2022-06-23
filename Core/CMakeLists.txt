cmake_minimum_required(VERSION 3.0.0)
project(Core VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(Math)
add_subdirectory(Renderer)

file(GLOB_RECURSE SRC src/*.cpp)

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.7
)
FetchContent_MakeAvailable(glfw)

add_library(Core SHARED Core.cpp ${SRC} ${INCLUDE})
target_link_libraries(${PROJECT_NAME} PUBLIC Math Renderer glfw)
target_include_directories(${PROJECT_NAME} PUBLIC include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
