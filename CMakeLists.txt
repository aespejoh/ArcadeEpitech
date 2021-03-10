cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)

project(globalProject)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/libs)
add_subdirectory(ncurses)
add_subdirectory(sdl)
add_subdirectory(sfml)
add_subdirectory(core)
