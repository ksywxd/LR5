#include "task1lib.h"
#include <gtest/gtest.h>

TEST(SimpleTest, BasicAssertion) {
    EXPECT_EQ(1, 1);
}

TEST(SumATest, Sum_2x2) {
    int n = 2;
    int** A = new int*[2];
    for ( int i = 0; i < n; i++) {
        A[i] = new int[n];
    }
    //чет строки нечет столбцы
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    EXPECT_EQ(sumA(A, n), 3);

    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
}