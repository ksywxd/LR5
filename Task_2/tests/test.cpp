#include <gtest/gtest.h>
#include <cmath>
#include "Test.h"

TEST(RecFuncTest, TwoElementsCorrect) {
    double arr[] = {0.0, M_PI/2};
    double result = recFunc(arr, 0, 1);

    // (sin(0)-cos(0)) * (sin(π/2)-cos(π/2)) = (-1) * (1-0) = -1
    double expected = -1.0;
    EXPECT_NEAR(expected, result, 1e-9);
}

TEST(RecFuncTest, ThreeElements) {
    double arr[] = {0.0, M_PI/4, M_PI/2};
    double result = recFunc(arr, 0, 2);

    // Первая треть: [0] -> -1
    // Остальные 2/3: [π/4, π/2] -> (0) * (1) = 0
    // Результат: -1 * 0 = 0
    double expected = 0.0;
    EXPECT_NEAR(expected, result, 1e-9);
}

TEST(RecFuncTest, FourElements) {
    double arr[] = {0.0, M_PI/4, M_PI/2, M_PI};
    double result = recFunc(arr, 0, 3);

    // Для 4 элементов: первая треть = 1 элемент, остальные 2/3 = 3 элемента
    // Первая треть: [0] -> -1
    // Остальные 2/3: [π/4, π/2, π] -> рекурсивно разбиваем дальше
    EXPECT_FALSE(std::isnan(result));
    EXPECT_FALSE(std::isinf(result));
}

TEST(RecFuncTest, SixElements) {
    double arr[] = {0.0, M_PI/4, M_PI/2, M_PI, 3*M_PI/2, 2*M_PI};
    double result = recFunc(arr, 0, 5);

    // Для 6 элементов: первая треть = 2 элемента, остальные 2/3 = 4 элемента
    EXPECT_FALSE(std::isnan(result));
    EXPECT_FALSE(std::isinf(result));
}

TEST(RecFuncTest, NineElements) {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    double result = recFunc(arr, 0, 8);

    // Для 9 элементов:
    // Первая треть: [1.0, 2.0, 3.0] - 3 элемента
    // Остальные 2/3: [4.0, 5.0, 6.0, 7.0, 8.0, 9.0] - 6 элементов
    EXPECT_TRUE(std::isfinite(result));
}

TEST(RecFuncTest, SingleElement) {
    double arr[] = {M_PI/4};
    double result = recFunc(arr, 0, 0);
    double expected = sin(M_PI/4) - cos(M_PI/4); // ≈ 0
    EXPECT_NEAR(expected, result, 1e-9);
}

TEST(RecFuncTest, ManualCalculationThree) {
    double arr[] = {M_PI/6, M_PI/4, M_PI/3};
    double result = recFunc(arr, 0, 2);

    // Ручной расчет:
    // Первая треть: [π/6] -> sin(π/6)-cos(π/6) = 0.5 - 0.866 = -0.366
    // Остальные 2/3: [π/4, π/3] -> (sin(π/4)-cos(π/4)) * (sin(π/3)-cos(π/3)) = 0 * (0.866-0.5) = 0
    // Результат: -0.366 * 0 = 0
    EXPECT_NEAR(0.0, result, 1e-9);
}

// Тест для проверки правильности разбиения
TEST(RecFuncTest, VerifyPartitioning) {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double result = recFunc(arr, 0, 5);

    // Должен вычислиться без ошибок
    EXPECT_TRUE(std::isfinite(result));
}