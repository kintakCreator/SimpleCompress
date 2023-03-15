cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME SimpleCompress)

project(${PROJECT_NAME} C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(core)
add_subdirectory(compress)
add_subdirectory(decompress)
