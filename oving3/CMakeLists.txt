cmake_minimum_required(VERSION 3.1)
project(oving3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(main main.cpp cannonball.h cannonball.cpp utilities.h utilities.cpp)
