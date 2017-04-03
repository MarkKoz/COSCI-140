cmake_minimum_required(VERSION 3.6)
project(Midterm)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
		include/Addition.h
		include/Division.h
		include/Game.h
		include/Multiplication.h
		include/Subtraction.h
		src/Addition.cpp
		src/Division.cpp
		src/Game.cpp
		src/Main.cpp
		src/Multiplication.cpp
		src/Subtraction.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Midterm ${SOURCE_FILES})

set_target_properties(Midterm PROPERTIES OUTPUT_NAME "Midterm")
