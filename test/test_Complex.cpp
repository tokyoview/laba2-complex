#include "TComplex.h"
#include <gtest.h>

// Тесты для конструктора
TEST(TComplexTest, Constructor) {
    TComplex<int> c1;
    EXPECT_EQ(0, c1.GetRe());
    EXPECT_EQ(0, c1.GetIm());

    TComplex<int> c2(3, 4);
    EXPECT_EQ(3, c2.GetRe());
    EXPECT_EQ(4, c2.GetIm());
}

// Тесты для оператора сложения
TEST(TComplexTest, Addition) {
    TComplex<int> c1(1, 2);
    TComplex<int> c2(3, 4);
    TComplex<int> result = c1 + c2;

    EXPECT_EQ(4, result.GetRe());
    EXPECT_EQ(6, result.GetIm());
}

// Тесты для оператора вычитания
TEST(TComplexTest, Subtraction) {
    TComplex<int> c1(5, 6);
    TComplex<int> c2(3, 4);
    TComplex<int> result = c1 - c2;

    EXPECT_EQ(2, result.GetRe());
    EXPECT_EQ(2, result.GetIm());
}

// Тесты для оператора умножения
TEST(TComplexTest, Multiplication) {
    TComplex<int> c1(1, 2);
    TComplex<int> c2(3, 4);
    TComplex<int> result = c1 * c2;

    EXPECT_EQ(-5, result.GetRe());  // (1*3 - 2*4) = -5
    EXPECT_EQ(10, result.GetIm()); // (1*4 + 2*3) = 10
}

// Тесты для оператора деления
TEST(TComplexTest, Division) {
    TComplex<double> c1(1, 2);
    TComplex<double> c2(3, 4);
    TComplex<double> result = c1 / c2;

    EXPECT_NEAR(0.44, result.GetRe(), 0.01);  // (1*3 + 2*4) / (3*3 + 4*4) = 11 / 25 = 0.44
    EXPECT_NEAR(0.08, result.GetIm(), 0.01);  // (2*3 - 1*4) / (3*3 + 4*4) = 2 / 25 = 0.08
}

// Тесты для оператора +=
TEST(TComplexTest, AdditionAssignment) {
    TComplex<int> c1(1, 2);
    TComplex<int> c2(3, 4);
    c1 += c2;

    EXPECT_EQ(4, c1.GetRe());
    EXPECT_EQ(6, c1.GetIm());
}

// Тесты для оператора -=
TEST(TComplexTest, SubtractionAssignment) {
    TComplex<int> c1(5, 6);
    TComplex<int> c2(3, 4);
    c1 -= c2;

    EXPECT_EQ(2, c1.GetRe());
    EXPECT_EQ(2, c1.GetIm());
}

// Тесты для оператора *=
TEST(TComplexTest, MultiplicationAssignment) {
    TComplex<int> c1(1, 2);
    TComplex<int> c2(3, 4);
    c1 *= c2;

    EXPECT_EQ(-5, c1.GetRe());  // (1*3 - 2*4) = -5
    EXPECT_EQ(-14, c1.GetIm()); // (1*4 + 2*3) = 10
}

// Тесты для оператора /=
TEST(TComplexTest, DivisionAssignment) {
    TComplex<double> c1(1, 2);
    TComplex<double> c2(3, 4);
    c1 /= c2;

    EXPECT_NEAR(0.44, c1.GetRe(), 0.01);  // (1*3 + 2*4) / (3*3 + 4*4) = 11 / 25 = 0.44
    EXPECT_NEAR(0.17, c1.GetIm(), 0.01);  // (2*3 - 1*4) / (3*3 + 4*4) = 2 / 25 = 0.08
}

// Тесты для оператора ==
TEST(TComplexTest, Equality) {
    TComplex<int> c1(1, 2);
    TComplex<int> c2(1, 2);
    TComplex<int> c3(3, 4);

    EXPECT_TRUE(c1 == c2);
    EXPECT_FALSE(c1 == c3);
}

// Тесты для оператора !=
TEST(TComplexTest, Inequality) {
    TComplex<int> c1(1, 2);
    TComplex<int> c2(1, 2);
    TComplex<int> c3(3, 4);

    EXPECT_FALSE(c1 != c2);
    EXPECT_TRUE(c1 != c3);
}