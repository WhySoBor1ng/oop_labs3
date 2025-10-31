add_library(Figures
        Figure.cpp
        Point.cpp
        Polygon.cpp
        Rectangle.cpp
        Square.cpp
        Trapezoid.cpp)

add_executable(main main.cpp)

target_link_libraries(main Figures)