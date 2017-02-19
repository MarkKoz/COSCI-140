cmake_minimum_required(VERSION 3.6)
project(Ch10-Quiz)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		src/Main.cpp src/Main.h)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Ch10-Quiz ${SOURCE_FILES})

set_target_properties(Ch10-Quiz PROPERTIES OUTPUT_NAME "Chapter 10 Quiz")
