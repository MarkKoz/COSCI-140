cmake_minimum_required(VERSION 3.6)
project(Ch15-Quiz)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		include/BasicShape.h
		include/Circle.h
		include/Rectangle.h
		src/BasicShape.cpp
		src/Circle.cpp
		src/Main.cpp
		src/Rectangle.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Ch15-Quiz ${SOURCE_FILES})

set_target_properties(Ch15-Quiz PROPERTIES OUTPUT_NAME "Chapter 15 Quiz")
