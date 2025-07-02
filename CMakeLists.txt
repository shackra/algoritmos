cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED On)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

project(Algoritmos C)

add_executable(bubble_sort ./bubble_sort.c)
add_executable(binary_search ./binary_search.c)

# misc
file(CREATE_LINK "${CMAKE_BINARY_DIR}/compile_commands.json"
     "${CMAKE_SOURCE_DIR}/compile_commands.json" SYMBOLIC)
