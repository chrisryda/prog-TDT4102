cmake_minimum_required(VERSION 3.1)
project(oving5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(main main.cpp Card.cpp Card.h CardDeck.cpp CardDeck.h)
