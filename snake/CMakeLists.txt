cmake_minimum_required(VERSION 3.17)
project(sdl2)

set(CMAKE_CXX_STANDARD 14)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
add_library(nibbler SHARED snakeGame.cpp ../include/snakeGame.hpp ../snake/player.cpp ../include/player.hpp)
set_target_properties(nibbler PROPERTIES PREFIX "arcade_")