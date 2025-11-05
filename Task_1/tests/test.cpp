#include "task1lib.h"
#include <gtest/gtest.h>

TEST(CreatMatrixATest, Matrix_1x1) {
    int** A = createMatrixA(1);
    EXPECT_EQ(A[0][0], 0);

    freeMatrix(A, 1);
}

TEST(CreateMatrixATest, Matrix_2x2) {

    // a[0][0] = 0   a[0][1] = 4
    // a[1][0] = 2   a[1][1] = 12
    int** A = createMatrixA(2);

    EXPECT_EQ(A[0][0], 0);
    EXPECT_EQ(A[0][1], 4);
    EXPECT_EQ(A[1][0], 2);
    EXPECT_EQ(A[1][1], 12);

    freeMatrix(A, 2);
}

TEST(CreateMatrixATest, Matrix_5x5) {

    // a[4][0] = 8   a[4][1] = 36  a[4][2] = 84   a[4][3] = 152   a[4][4] = 615
    int** A = createMatrixA(5);

    EXPECT_EQ(A[4][0], 8);
    EXPECT_EQ(A[4][1], 36);
    EXPECT_EQ(A[4][2], 84);
    EXPECT_EQ(A[4][3], 152);
    EXPECT_EQ(A[4][4], 240);

    freeMatrix(A, 5);
}

TEST(CreateMatrixATest, Matrix_6x6) {

    // a[5][0] = 15   a[5][1] = 33   a[5][4] = 87   a[5][5] = 105
    int** A = createMatrixA(6);

    EXPECT_EQ(A[5][0], 15);
    EXPECT_EQ(A[5][1], 33);
    EXPECT_EQ(A[5][4], 87);
    EXPECT_EQ(A[5][5], 105);

    freeMatrix(A, 6);
}

TEST(MatrixTest, TransposeMatrix) {
    int n = 2;
    int** A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    int** B = transMatrix(A, n);

    EXPECT_EQ(B[0][0], 1);
    EXPECT_EQ(B[0][1], 3);
    EXPECT_EQ(B[1][0], 2);
    EXPECT_EQ(B[1][1], 4);

    freeMatrix(A, n);
    freeMatrix(B, n);
}

TEST(SumATest, Sum_4x4) {
    int n = 4;
    int count = 1;
    int** A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }
    //чет строки нечет столбцы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = count++;
        }
    }
    EXPECT_EQ(sumA(A, n), 40);

    freeMatrix(A, n);
}

TEST(SumBTest, Sum_4x4) {
    int n = 4;
    int count = 1;
    int** B = new int*[n];
    for (int i = 0; i < n; i++) {
        B[i] = new int[n];
    }
    //чет строки нечет столбцы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = count++;
        }
    }
    EXPECT_EQ(sumB(B, n), 28);

    freeMatrix(B, n);
}