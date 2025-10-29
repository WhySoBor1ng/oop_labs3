cmake_minimum_required(VERSION 4.0)
project(oop_labs3)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(oop_labs3
        src/Figure.cpp
        src/Point.cpp
        src/Polygon.cpp
        src/Rectangle.cpp)
