#include <gtest/gtest.h>
#include "Test.h"

TEST(FindZeroTest, NoZeros) {
    double** arr = new double*[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new double[2];
        for (int j = 0; j < 2; j++) {
            arr[i][j] = 1.0;
        }
    }

    EXPECT_EQ(findZero(arr, 2, 2), 0);
    freeArr(arr, 2);
}

TEST(FindZeroTest, AllZeros) {
    double** arr = new double*[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new double[2]{0, 0};
    }

    EXPECT_EQ(findZero(arr, 2, 2), 4);
    freeArr(arr, 2);
}

TEST(FindZeroTest, SomeZeros) {
    double** arr = new double*[3];
    arr[0] = new double[2]{1.0, 0.0};
    arr[1] = new double[2]{0.0, 2.0};
    arr[2] = new double[2]{0.0, 0.0};

    EXPECT_EQ(findZero(arr, 3, 2), 4);
    freeArr(arr, 3);
}

TEST(FindZeroTest, SingleElementZero) {
    double** arr = new double*[1];
    arr[0] = new double[1]{0.0};

    EXPECT_EQ(findZero(arr, 1, 1), 1);
    freeArr(arr, 1);
}

TEST(FindZeroTest, SingleElementNonZero) {
    double** arr = new double*[1];
    arr[0] = new double[1]{5.0};

    EXPECT_EQ(findZero(arr, 1, 1), 0);
    freeArr(arr, 1);
}

TEST(FindIndexTest, BasicTest) {
    double** arr = new double*[2];
    arr[0] = new double[3]{1.0, 0.0, 2.0};
    arr[1] = new double[3]{0.0, 3.0, 0.0};

    int* arrI = new int[3]; // Максимум 3 нуля
    int* arrJ = new int[3];

    findIndex(arrI, arrJ, arr, 2, 3);

    // Проверяем индексы нулевых элементов
    EXPECT_EQ(arrI[0], 0);
    EXPECT_EQ(arrJ[0], 1);

    EXPECT_EQ(arrI[1], 1);
    EXPECT_EQ(arrJ[1], 0);

    EXPECT_EQ(arrI[2], 1);
    EXPECT_EQ(arrJ[2], 2);

    delete[] arrI;
    delete[] arrJ;
    freeArr(arr, 2);
}

TEST(FindIndexTest, NoZeros) {
    double** arr = new double*[2];
    arr[0] = new double[2]{1.0, 2.0};
    arr[1] = new double[2]{3.0, 4.0};

    int* arrI = new int[1]; // Выделяем память, но не должно быть нулей
    int* arrJ = new int[1];

    findIndex(arrI, arrJ, arr, 2, 2);

    // Массивы arrI и arrJ должны остаться пустыми
    // (функция не записывает ничего, так как нет нулей)

    delete[] arrI;
    delete[] arrJ;
    freeArr(arr, 2);
}

TEST(FillOutTest, BasicTest) {
    double** arr = new double*[2];
    arr[0] = new double[2]{1.0, 2.0};
    arr[1] = new double[2]{3.0, 4.0};

    double* result = fillOut(arr, 2, 2);

    EXPECT_DOUBLE_EQ(result[0], 1.0);
    EXPECT_DOUBLE_EQ(result[1], 2.0);
    EXPECT_DOUBLE_EQ(result[2], 3.0);
    EXPECT_DOUBLE_EQ(result[3], 4.0);

    delete[] result;
    freeArr(arr, 2);
}

TEST(FillOutTest, SingleElement) {
    double** arr = new double*[1];
    arr[0] = new double[1]{5.5};

    double* result = fillOut(arr, 1, 1);

    EXPECT_DOUBLE_EQ(result[0], 5.5);

    delete[] result;
    freeArr(arr, 1);
}

TEST(FillOutTest, RectangularMatrix) {
    double** arr = new double*[2];
    arr[0] = new double[3]{1.0, 2.0, 3.0};
    arr[1] = new double[3]{4.0, 5.0, 6.0};

    double* result = fillOut(arr, 2, 3);

    EXPECT_DOUBLE_EQ(result[0], 1.0);
    EXPECT_DOUBLE_EQ(result[1], 2.0);
    EXPECT_DOUBLE_EQ(result[2], 3.0);
    EXPECT_DOUBLE_EQ(result[3], 4.0);
    EXPECT_DOUBLE_EQ(result[4], 5.0);
    EXPECT_DOUBLE_EQ(result[5], 6.0);

    delete[] result;
    freeArr(arr, 2);
}

TEST(ReverseTest, BasicTest) {
    double* lineArr = new double[4]{1.0, 2.0, 3.0, 4.0};
    double** result = reverse(lineArr, 2, 2);

    EXPECT_DOUBLE_EQ(result[0][0], 4.0);
    EXPECT_DOUBLE_EQ(result[0][1], 3.0);
    EXPECT_DOUBLE_EQ(result[1][0], 2.0);
    EXPECT_DOUBLE_EQ(result[1][1], 1.0);

    delete[] lineArr;
    freeArr(result, 2);
}

TEST(ReverseTest, SingleElement) {
    double* lineArr = new double[1]{7.5};
    double** result = reverse(lineArr, 1, 1);

    EXPECT_DOUBLE_EQ(result[0][0], 7.5);

    delete[] lineArr;
    freeArr(result, 1);
}

TEST(ReverseTest, RectangularMatrix) {
    double* lineArr = new double[6]{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double** result = reverse(lineArr, 2, 3);

    EXPECT_DOUBLE_EQ(result[0][0], 6.0);
    EXPECT_DOUBLE_EQ(result[0][1], 5.0);
    EXPECT_DOUBLE_EQ(result[0][2], 4.0);
    EXPECT_DOUBLE_EQ(result[1][0], 3.0);
    EXPECT_DOUBLE_EQ(result[1][1], 2.0);
    EXPECT_DOUBLE_EQ(result[1][2], 1.0);

    delete[] lineArr;
    freeArr(result, 2);
}

TEST(IntegrationTest, FullWorkflow) {
    double** original = new double*[2];
    original[0] = new double[2]{1.0, 0.0};
    original[1] = new double[2]{0.0, 2.0};

    int zeroCount = findZero(original, 2, 2);
    EXPECT_EQ(zeroCount, 2);

    int* arrI = new int[zeroCount];
    int* arrJ = new int[zeroCount];
    findIndex(arrI, arrJ, original, 2, 2);

    EXPECT_EQ(arrI[0], 0);
    EXPECT_EQ(arrJ[0], 1);
    EXPECT_EQ(arrI[1], 1);
    EXPECT_EQ(arrJ[1], 0);

    double* linear = fillOut(original, 2, 2);
    EXPECT_DOUBLE_EQ(linear[0], 1.0);
    EXPECT_DOUBLE_EQ(linear[1], 0.0);
    EXPECT_DOUBLE_EQ(linear[2], 0.0);
    EXPECT_DOUBLE_EQ(linear[3], 2.0);

    double** reversed = reverse(linear, 2, 2);
    EXPECT_DOUBLE_EQ(reversed[0][0], 2.0);
    EXPECT_DOUBLE_EQ(reversed[0][1], 0.0);
    EXPECT_DOUBLE_EQ(reversed[1][0], 0.0);
    EXPECT_DOUBLE_EQ(reversed[1][1], 1.0);

    delete[] arrI;
    delete[] arrJ;
    delete[] linear;
    freeArr(original, 2);
    freeArr(reversed, 2);
}