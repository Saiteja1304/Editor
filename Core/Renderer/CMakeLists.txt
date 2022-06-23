cmake_minimum_required(VERSION 3.0.0)
project(Renderer VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_definitions(EVALUATION_ENABLED)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE INCLUDE include/*.hpp)

add_library(Renderer SHARED src/Renderer.cpp src/glad.c
${SRC} ${INCLUDE})

target_include_directories(${PROJECT_NAME} PUBLIC include/)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
