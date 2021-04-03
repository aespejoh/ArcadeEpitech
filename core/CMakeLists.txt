cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)

project(arcade)

add_executable(arcade main.cpp core.cpp ../include/core.h iDisplayModule.cpp ../include/iDisplayModule.hpp IGame.cpp ../include/IGame.hpp Exception.cpp ../include/Exception.hpp Errors.cpp ../include/Errors.hpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
SET(LIBS    "-Wl,--no-as-needed -ldl -lncurses -lSDL2 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LIBS}")