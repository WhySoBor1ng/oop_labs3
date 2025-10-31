#include <gtest/gtest.h>
#include <sstream>
#include <array>
#include "Rectangle.h"
#include "Square.h"
#include "Trapezoid.h"


// --- Rectangle ---

TEST(RectangleTests, DefaultConstructor) {
    Rectangle rect;
    Point center = rect.get_center();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(RectangleTests, CopyConstructor) {
    Rectangle original;
    std::istringstream is("0 0 2 0 2 1 0 1");
    is >> original;
    Rectangle copy(original);
    EXPECT_TRUE(copy == original);
}

TEST(RectangleTests, MoveConstructor) {
    Rectangle original;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> original;
    Rectangle expected;
    std::istringstream is2("0 0 2 0 2 1 0 1");
    is2 >> expected;
    Rectangle moved(std::move(original));
    EXPECT_TRUE(moved == expected);
}

TEST(RectangleTests, CopyAssignmentOperator) {
    Rectangle original;
    std::istringstream is("0 0 2 0 2 1 0 1");
    is >> original;
    Rectangle copy;
    copy = original;
    EXPECT_TRUE(copy == original);
}

TEST(RectangleTests, MoveAssignmentOperator) {
    Rectangle original;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> original;
    Rectangle expected;
    std::istringstream is2("0 0 2 0 2 1 0 1");
    is2 >> expected;
    Rectangle moved;
    moved = std::move(original);
    EXPECT_TRUE(moved == expected);
}

TEST(RectangleTests, SelfCopyAssignment) {
    Rectangle rect;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> rect;
    Rectangle expected;
    std::istringstream is2("0 0 2 0 2 1 0 1");
    is2 >> expected;
    rect = rect;
    EXPECT_TRUE(rect == expected);
}

TEST(RectangleTests, SelfMoveAssignment) {
    Rectangle rect;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> rect;
    Rectangle expected;
    std::istringstream is2("0 0 2 0 2 1 0 1");
    is2 >> expected;
    rect = std::move(rect);
    EXPECT_TRUE(rect == expected);
}

TEST(RectangleTests, ComparisonOperators) {
    Rectangle a, b, c;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    std::istringstream is2("0 0 2 0 2 1 0 1");
    std::istringstream is3("0 0 3 0 3 1 0 1");
    is1 >> a;
    is2 >> b;
    is3 >> c;
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(RectangleTests, GetGeometricCenter) {
    Rectangle rect;
    std::istringstream is("0 0 2 0 2 1 0 1");
    is >> rect;
    Point center = rect.get_center();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 0.5);
}

TEST(RectangleTests, AreaCalculation) {
    Rectangle rect;
    std::istringstream is("0 0 2 0 2 1 0 1");
    is >> rect;
    double area = static_cast<double>(rect);
    EXPECT_NEAR(area, 2.0, 0.01);
}

TEST(RectangleTests, AreaCalculationZero) {
    Rectangle rect;
    std::istringstream is("0 0 0 0 0 0 0 0");
    is >> rect;
    double area = static_cast<double>(rect);
    EXPECT_DOUBLE_EQ(area, 0.0);
}

TEST(RectangleTests, InputStreamInvalidInput) {
    Rectangle rect;
    std::istringstream is("a b c d e f g h");
    EXPECT_THROW(is >> rect, std::invalid_argument);
}

TEST(RectangleTests, OutputStreamOperator) {
    Rectangle rect;
    std::istringstream is("0 0 2 0 2 1 0 1");
    is >> rect;
    std::ostringstream os;
    os << rect;
    EXPECT_FALSE(os.str().empty());
    EXPECT_NE(os.str().find('('), std::string::npos);
}
// --- Square ---

TEST(SquareTests, DefaultConstructor) {
    Square square;
    Point center = square.get_center();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(SquareTests, CopyConstructor) {
    Square original;
    std::istringstream is("0 0 1 0 1 1 0 1");
    is >> original;
    Square copy(original);
    EXPECT_TRUE(copy == original);
}

TEST(SquareTests, MoveConstructor) {
    Square original;
    std::istringstream is1("0 0 1 0 1 1 0 1");
    is1 >> original;
    Square expected;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> expected;
    Square moved(std::move(original));
    EXPECT_TRUE(moved == expected);
}

TEST(SquareTests, CopyAssignmentOperator) {
    Square original;
    std::istringstream is("0 0 1 0 1 1 0 1");
    is >> original;
    Square copy;
    copy = original;
    EXPECT_TRUE(copy == original);
}

TEST(SquareTests, MoveAssignmentOperator) {
    Square original;
    std::istringstream is1("0 0 1 0 1 1 0 1");
    is1 >> original;
    Square expected;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> expected;
    Square moved;
    moved = std::move(original);
    EXPECT_TRUE(moved == expected);
}

TEST(SquareTests, SelfCopyAssignment) {
    Square square;
    std::istringstream is1("0 0 1 0 1 1 0 1");
    is1 >> square;
    Square expected;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> expected;
    square = square;
    EXPECT_TRUE(square == expected);
}

TEST(SquareTests, SelfMoveAssignment) {
    Square square;
    std::istringstream is1("0 0 1 0 1 1 0 1");
    is1 >> square;
    Square expected;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> expected;
    square = std::move(square);
    EXPECT_TRUE(square == expected);
}

TEST(SquareTests, ComparisonOperators) {
    Square a, b, c;
    std::istringstream is1("0 0 1 0 1 1 0 1");
    std::istringstream is2("0 0 1 0 1 1 0 1");
    std::istringstream is3("0 0 2 0 2 2 0 2");
    is1 >> a;
    is2 >> b;
    is3 >> c;
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(SquareTests, GetGeometricCenter) {
    Square square;
    std::istringstream is("0 0 1 0 1 1 0 1");
    is >> square;
    Point center = square.get_center();
    EXPECT_DOUBLE_EQ(center.x, 0.5);
    EXPECT_DOUBLE_EQ(center.y, 0.5);
}

TEST(SquareTests, AreaCalculation) {
    Square square;
    std::istringstream is("0 0 1 0 1 1 0 1");
    is >> square;
    double area = static_cast<double>(square);
    EXPECT_NEAR(area, 1.0, 0.01);
}

TEST(SquareTests, InputStreamInvalidInput) {
    Square square;
    std::istringstream is("a b c d e f g h");
    EXPECT_THROW(is >> square, std::invalid_argument);
}

TEST(SquareTests, OutputStreamOperator) {
    Square square;
    std::istringstream is("0 0 1 0 1 1 0 1");
    is >> square;
    std::ostringstream os;
    os << square;
    EXPECT_FALSE(os.str().empty());
    EXPECT_NE(os.str().find('('), std::string::npos);
}

// --- Trapezoid ---

TEST(TrapezoidTests, DefaultConstructor) {
    Trapezoid trap;
    Point center = trap.get_center();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(TrapezoidTests, CopyConstructor) {
    Trapezoid original;
    std::istringstream is("0 0 2 0 3 1 1 1");
    is >> original;
    Trapezoid copy(original);
    EXPECT_TRUE(copy == original);
}

TEST(TrapezoidTests, MoveConstructor) {
    Trapezoid original;
    std::istringstream is1("0 0 2 0 3 1 1 1");
    is1 >> original;
    Trapezoid expected;
    std::istringstream is2("0 0 2 0 3 1 1 1");
    is2 >> expected;
    Trapezoid moved(std::move(original));
    EXPECT_TRUE(moved == expected);
}

TEST(TrapezoidTests, CopyAssignmentOperator) {
    Trapezoid original;
    std::istringstream is("0 0 2 0 3 1 1 1");
    is >> original;
    Trapezoid copy;
    copy = original;
    EXPECT_TRUE(copy == original);
}

TEST(TrapezoidTests, MoveAssignmentOperator) {
    Trapezoid original;
    std::istringstream is1("0 0 2 0 3 1 1 1");
    is1 >> original;
    Trapezoid expected;
    std::istringstream is2("0 0 2 0 3 1 1 1");
    is2 >> expected;
    Trapezoid moved;
    moved = std::move(original);
    EXPECT_TRUE(moved == expected);
}

TEST(TrapezoidTests, SelfCopyAssignment) {
    Trapezoid trap;
    std::istringstream is1("0 0 2 0 3 1 1 1");
    is1 >> trap;
    Trapezoid expected;
    std::istringstream is2("0 0 2 0 3 1 1 1");
    is2 >> expected;
    trap = trap;
    EXPECT_TRUE(trap == expected);
}

TEST(TrapezoidTests, SelfMoveAssignment) {
    Trapezoid trap;
    std::istringstream is1("0 0 2 0 3 1 1 1");
    is1 >> trap;
    Trapezoid expected;
    std::istringstream is2("0 0 2 0 3 1 1 1");
    is2 >> expected;
    trap = std::move(trap);
    EXPECT_TRUE(trap == expected);
}

TEST(TrapezoidTests, ComparisonOperators) {
    Trapezoid a, b, c;
    std::istringstream is1("0 0 2 0 3 1 1 1");
    std::istringstream is2("0 0 2 0 3 1 1 1");
    std::istringstream is3("0 0 3 0 4 1 2 1");
    is1 >> a;
    is2 >> b;
    is3 >> c;
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(TrapezoidTests, GetGeometricCenter) {
    Trapezoid trap;
    std::istringstream is("0 0 2 0 3 1 1 1");
    is >> trap;
    Point center = trap.get_center();
    EXPECT_DOUBLE_EQ(center.x, 1.5);
    EXPECT_DOUBLE_EQ(center.y, 0.5);
}

TEST(TrapezoidTests, AreaCalculation) {
    Trapezoid trap;
    std::istringstream is("0 0 2 0 3 1 1 1");
    is >> trap;
    double area = static_cast<double>(trap);
    EXPECT_NEAR(area, 1.5, 0.01);
}

TEST(TrapezoidTests, InputStreamInvalidInput) {
    Trapezoid trap;
    std::istringstream is("a b c d e f g h");
    EXPECT_THROW(is >> trap, std::invalid_argument);
}

TEST(TrapezoidTests, OutputStreamOperator) {
    Trapezoid trap;
    std::istringstream is("0 0 2 0 3 1 1 1");
    is >> trap;
    std::ostringstream os;
    os << trap;
    EXPECT_FALSE(os.str().empty());
    EXPECT_NE(os.str().find('('), std::string::npos);
}

TEST(FigureArrayTests, CreateAndStoreDifferentFiguresInArray) {
    std::array<Figure*, 3> figures{};
    Rectangle rect;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> rect;
    figures[0] = &rect;
    Square square;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> square;
    figures[1] = &square;
    Trapezoid trap;
    std::istringstream is3("0 0 2 0 3 1 1 1");
    is3 >> trap;
    figures[2] = &trap;

    EXPECT_EQ(figures.size(), 3);
}

TEST(FigureArrayTests, CalculateGeometricCentersDifferentFigures) {
    std::array<Figure*, 3> figures;
    Rectangle rect;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> rect;
    figures[0] = &rect;
    Square square;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> square;
    figures[1] = &square;
    Trapezoid trap;
    std::istringstream is3("0 0 2 0 3 1 1 1");
    is3 >> trap;
    figures[2] = &trap;

    for (size_t i = 0; i < figures.size(); ++i) {
        Point c = figures[i]->get_center();
        EXPECT_NO_THROW((void)c);
    }
}

TEST(FigureArrayTests, CalculateAreasDifferentFigures) {
    std::array<Figure*, 3> figures;
    Rectangle rect;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> rect;
    figures[0] = &rect;
    Square square;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> square;
    figures[1] = &square;
    Trapezoid trap;
    std::istringstream is3("0 0 2 0 3 1 1 1");
    is3 >> trap;
    figures[2] = &trap;

    for (size_t i = 0; i < figures.size(); ++i) {
        double area = static_cast<double>(*figures[i]);
        EXPECT_GT(area, 0.0);
    }
}

TEST(FigureArrayTests, CalculateTotalAreaDifferentFigures) {
    std::array<Figure*, 3> figures;
    Rectangle rect;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> rect;
    figures[0] = &rect;
    Square square;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> square;
    figures[1] = &square;
    Trapezoid trap;
    std::istringstream is3("0 0 2 0 3 1 1 1");
    is3 >> trap;
    figures[2] = &trap;

    double total = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        total += static_cast<double>(*figures[i]);
    }
    EXPECT_GT(total, 0.0);
}

TEST(FigureArrayTests, RemoveByIndexDifferentFigures) {
    std::array<Figure*, 3> figures{};
    Rectangle rect;
    std::istringstream is1("0 0 2 0 2 1 0 1");
    is1 >> rect;
    figures[0] = &rect;
    Square square;
    std::istringstream is2("0 0 1 0 1 1 0 1");
    is2 >> square;
    figures[1] = &square;
    Trapezoid trap;
    std::istringstream is3("0 0 2 0 3 1 1 1");
    is3 >> trap;
    figures[2] = &trap;

    figures[0] = figures[1];
    figures[1] = figures[2];
    EXPECT_EQ(figures[0]->get_center().x, square.get_center().x);
}

TEST(FigureArrayTests, EmptyArrayDifferentFigures) {
    std::array<Figure*, 0> figures;
    EXPECT_TRUE(figures.empty());
}