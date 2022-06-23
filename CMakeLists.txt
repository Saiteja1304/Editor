cmake_minimum_required(VERSION 3.0.0)
project(Editor VERSION 0.1.0)

add_subdirectory(Core)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE UI UIlib/*.cpp)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
add_compile_definitions(EVALUATION_ENABLED)
message("[BUILD][DEBUG]")
endif(CMAKE_BUILD_TYPE STREQUAL Debug)

if(CMAKE_BUILD_TYPE STREQUAL Release)
message("[BUILD][RELEASE]")
endif(CMAKE_BUILD_TYPE STREQUAL Release)


add_executable(Editor EntryPoint.cpp ${SRC} ${UI})

target_compile_options(${PROJECT_NAME} PRIVATE 
-Wall)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

target_include_directories(${PROJECT_NAME} PUBLIC include/ UIlib/)
target_link_libraries(${PROJECT_NAME} PUBLIC Core)
