#include <gtest/gtest.h>
#include "Test.h"

//нахождение четных элементов на диагонали
TEST(MatrixTest, FindEvenElementsOnDiagonal) {
    int count = 0;
    int n = 3;
    int k = 3;
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[k];
    }

    //на диагонали 2, 3, 4
    matrix[0][0] = 2; matrix[0][1] = 1; matrix[0][2] = 1;
    matrix[1][0] = 1; matrix[1][1] = 3; matrix[1][2] = 1;
    matrix[2][0] = 1; matrix[2][1] = 1; matrix[2][2] = 4;

    int* result = findElOnD(matrix, n, k, count);

    //2 четных  2 и 4
    EXPECT_EQ(count, 2);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 4);

    delete[] result;
}

//умножение элементов
TEST(MatrixTest, MultiplyElements) {
    int testArray[] = {2, 4, 6};
    int count = 3;
    int result = multiply(testArray, count);

    EXPECT_EQ(result, 48);
}

// Тест для случая, когда нет четных элементов
TEST(MatrixTest, NoEvenElements) {
    int count = 0;
    int n = 3;
    int k = 3;
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[k];
    }

    //на диагонали только нечетные
    matrix[0][0] = 1; matrix[0][1] = 1; matrix[0][2] = 1;
    matrix[1][0] = 1; matrix[1][1] = 3; matrix[1][2] = 1;
    matrix[2][0] = 1; matrix[2][1] = 1; matrix[2][2] = 5;

    int* result = findElOnD(matrix, n, k, count);

    EXPECT_EQ(count, 0);
    EXPECT_EQ(result, nullptr);
}

//multiply с одним элементом
TEST(MultiplyTest, SingleElement) {
    int testArray[] = {5};
    int result = multiply(testArray, 1);
    EXPECT_EQ(result, 5);
}

//multiply с пустым массивом
TEST(MultiplyTest, EmptyArray) {
    int* testArray = nullptr;
    int result = multiply(testArray, 0);
    EXPECT_EQ(result, 1); // Произведение пустого массива = 1
}

//для неквадратной матрицы
TEST(MatrixTest, NonSquareMatrix) {
    int** matrix = new int*[2];
    for (int i = 0; i < 2; i++) {
        matrix[i] = new int[3];
    }

    // 2x3, диагональ 2 элемента
    matrix[0][0] = 2; matrix[0][1] = 1; matrix[0][2] = 1;
    matrix[1][0] = 1; matrix[1][1] = 4; matrix[1][2] = 1;

    int count = 0;
    int* result = findElOnD(matrix, 2, 3, count);

    EXPECT_EQ(count, 2); // Оба четные 2 и 4
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 4);

    delete[] result;
    for (int i = 0; i < 2; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}