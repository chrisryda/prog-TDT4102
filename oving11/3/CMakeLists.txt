cmake_minimum_required(VERSION 3.1)
project(oving11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

link_libraries(stdc++fs)

add_executable(main main.cpp LinkedList.cpp LinkedList.h)
