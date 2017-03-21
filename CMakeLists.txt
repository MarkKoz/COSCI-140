cmake_minimum_required(VERSION 3.6)
project(Ch14-Quiz)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		src/Main.cpp
		src/DateImp.cpp
		src/Date.h)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Ch14-Quiz ${SOURCE_FILES})

set_target_properties(Ch14-Quiz PROPERTIES OUTPUT_NAME "Chapter 14 Quiz")
