cmake_minimum_required(VERSION 3.29)
project(Pi C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DIS_DEBUG")

add_executable(Pi Source/Main.c)
target_link_libraries(Pi m)