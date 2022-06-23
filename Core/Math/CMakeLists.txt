cmake_minimum_required(VERSION 3.0.0)
project(Math VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE INCLUDE include/*.hpp)

add_library(Math SHARED Math.cpp ${SRC} ${INCLUDE})
target_include_directories(${PROJECT_NAME} PUBLIC include/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
