cmake_minimum_required(VERSION 3.17)
project(sdl)

set(CMAKE_CXX_STANDARD 14)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
add_library(sdl SHARED sdl.cpp ../include/libs/sdl.h)