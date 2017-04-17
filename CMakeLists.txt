cmake_minimum_required(VERSION 3.6)
project(Ch16-Quiz)

include_directories(include)
set(SOURCE_FILES
		include/ArrayOfObjects.h
		include/Circle.h
		include/Rectangle.h
		src/Main.cpp)
add_executable(Ch16-Quiz ${SOURCE_FILES})

list(APPEND FLAGS_WARN
		-Wall
		-Wextra
		-Wfloat-equal
		-Wundef
		-Wcast-align
		-Wwrite-strings
		-Wlogical-op
		-Wmissing-declarations
		-Wredundant-decls
		-Wshadow
		-Woverloaded-virtual)
list(APPEND FLAGS_STATIC
		-static-libgcc
		-static-libstdc++
		-static)
list(APPEND FLAGS_DEBUG
		${FLAGS_WARN}
		-ggdb
		-g3)
list(APPEND FLAGS_RELEASE
		${FLAGS_WARN}
		-o2
		-DNDEBUG)

set(CMAKE_CXX_STANDARD 14)
target_compile_options(Ch16-Quiz PUBLIC "$<$<CONFIG:DEBUG>:${FLAGS_DEBUG}>")
target_compile_options(Ch16-Quiz PUBLIC "$<$<CONFIG:RELEASE>:${FLAGS_RELEASE}>")
target_link_libraries(Ch16-Quiz "$<$<CONFIG:RELEASE>:${FLAGS_STATIC}>")
set_target_properties(Ch16-Quiz PROPERTIES OUTPUT_NAME "Chapter 16 Quiz")
