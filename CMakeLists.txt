cmake_minimum_required(VERSION 3.6)
project(Chapter_09___Quiz_01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		src/Main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Chapter_09___Quiz_01 ${SOURCE_FILES})

set_target_properties(Chapter_09___Quiz_01 PROPERTIES OUTPUT_NAME "Chapter 09 - Quiz 01")