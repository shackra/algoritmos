cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED On)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

project(Algoritmos C)

add_executable(bubble_sort ./codigo\ fuente/bubble_sort.c)
add_executable(binary_search ./codigo\ fuente/binary_search.c)
add_executable(two_crystal_balls ./codigo\ fuente/pondering_my_crystal_balls.c)
# Enlaza math.h
target_link_libraries(two_crystal_balls PRIVATE m)

# misc
file(CREATE_LINK "${CMAKE_BINARY_DIR}/compile_commands.json"
     "${CMAKE_SOURCE_DIR}/compile_commands.json" SYMBOLIC)
