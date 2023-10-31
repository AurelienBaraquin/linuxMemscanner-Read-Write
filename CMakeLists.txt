cmake_minimum_required(VERSION 3.0)
project(Project)

file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.hpp"
    "src/*.h"
    "src/class/*.cpp"
)

add_executable(a.out ${SOURCES})

target_include_directories(a.out PUBLIC include include/class)

add_compile_options(-Wall -Wextra)

target_link_libraries(a.out)
