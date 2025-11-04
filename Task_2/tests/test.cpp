#include <gtest/gtest.h>
#include "Test.h"
#include <cmath>

//Один элемент
TEST(RecFuncTest, SingleElement) {
    double arr[] = {0.0};
    double result = recFunc(arr, 0, 0);
    EXPECT_NEAR(-1, result, 1e-9);
}

//Два элемента
TEST(RecFuncTest, TwoElements) {
    double arr[] = {0.0, M_PI/2};
    double result = recFunc(arr, 0, 1);

    //(sin(0)-cos(0)) * (sin(0)-cos(0)) = (-1) * (-1) = 1
    double first_elem = sin(0.0) - cos(0.0); // -1
    EXPECT_NEAR(1, result, 1e-9);
}

//Три элемента
TEST(RecFuncTest, ThreeElements) {
    double arr[] = {0.0, M_PI/4, M_PI/2};
    double result = recFunc(arr, 0, 2);

    // Проверяем что результат вычислен (не NaN)
    EXPECT_FALSE(std::isnan(result));
    EXPECT_FALSE(std::isinf(result));
}

//Четыре элемента
TEST(RecFuncTest, FourElements) {
    double arr[] = {1.0, 2.0, 3.0, 4.0};
    double result = recFunc(arr, 0, 3);

    //результат конечное число
    EXPECT_TRUE(std::isfinite(result));
}

//Отрицательные числа
TEST(RecFuncTest, NegativeNumbers) {
    double arr[] = {-1.0, -2.0, -3.0};
    double result = recFunc(arr, 0, 2);

    EXPECT_FALSE(std::isnan(result));
    EXPECT_FALSE(std::isinf(result));
}

//Все нули
TEST(RecFuncTest, AllZeros) {
    double arr[] = {0.0, 0.0, 0.0, 0.0};
    double result = recFunc(arr, 0, 3);

    EXPECT_TRUE(std::isfinite(result));
}

TEST(RecFuncTest, SpecialValues) {
    double arr[] = {0.0, M_PI/2, M_PI, 3*M_PI/2};
    double result = recFunc(arr, 0, 3);

    EXPECT_FALSE(std::isnan(result));
}

//не с начала
TEST(RecFuncTest, SubArray) {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    //[2.0, 3.0, 4.0] - индексы 1,2,3
    double result = recFunc(arr, 1, 3);

    EXPECT_TRUE(std::isfinite(result));
}

TEST(RecFuncTest, SpecificCalculation) {
    double arr[] = {M_PI/6}; // 30 градусов
    double result = recFunc(arr, 0, 0);
    double expected = sin(M_PI/6) - cos(M_PI/6);
    EXPECT_NEAR(expected, result, 1e-9);
}

//Очень большие числа
TEST(RecFuncTest, VeryLargeNumbers) {
    double arr[] = {1e10, 1e15, 1e20};
    double result = recFunc(arr, 0, 2);

    // Может быть inf из-за переполнения, но не NaN
    EXPECT_FALSE(std::isnan(result));
}

TEST(RecFuncTest, SingleElementInMiddle) {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    //один элемент в середине - индекс 2
    double result = recFunc(arr, 2, 2);
    double expected = sin(3.0) - cos(3.0);
    EXPECT_NEAR(expected, result, 1e-9);
}

TEST(RecFuncTest, KnownValues) {
    // Для угла π/4: sin(π/4) = cos(π/4) = √2/2, разность = 0
    double arr[] = {M_PI/4};
    double result = recFunc(arr, 0, 0);
    EXPECT_NEAR(0.0, result, 1e-9);
}

// Один элемент с большим значением
TEST(RecFuncTest, SingleLargeValue) {
    double arr[] = {100.0};
    double result = recFunc(arr, 0, 0);
    double expected = sin(100.0) - cos(100.0);
    EXPECT_NEAR(expected, result, 1e-9);
}

//Два одинаковых элемента
TEST(RecFuncTest, TwoIdenticalElements) {
    double arr[] = {1.5, 1.5};
    double result = recFunc(arr, 0, 1);

    //(sin(1.5)-cos(1.5)) * (sin(1.5)-cos(1.5))
    double elem = sin(1.5) - cos(1.5);
    double expected = elem * elem;
    EXPECT_NEAR(expected, result, 1e-9);
}

//минимальный диапазон
TEST(RecFuncTest, MinimalRange) {
    double arr[] = {1.0};
    double result = recFunc(arr, 0, 0);
    EXPECT_TRUE(std::isfinite(result));
}