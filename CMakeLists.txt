cmake_minimum_required(VERSION 3.6)
project(Ch16-Quiz)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		src/ArrayOfObjects.h
		src/Circle.h
		src/Main.cpp
		src/Rectangle.h)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Ch16-Quiz ${SOURCE_FILES})

set_target_properties(Ch16-Quiz PROPERTIES OUTPUT_NAME "Chapter 16 Quiz")
