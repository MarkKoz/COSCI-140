cmake_minimum_required(VERSION 3.6)
project(Ch13-Quiz)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		src/Main.cpp
		src/IntegersImp.cpp
		src/Integers.h)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Ch13-Quiz ${SOURCE_FILES})

set_target_properties(Ch13-Quiz PROPERTIES OUTPUT_NAME "Chapter 13 Quiz")
