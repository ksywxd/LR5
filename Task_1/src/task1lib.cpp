#include "task1lib.h"
#include <iostream>

int** createMatrixA(int n){
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int [n];
        for (int j = 0; j < n; j++) {
            int a = i + 1;
            int b = j + 1;
            if (a <= 5) {
                A[i][j] = 2 * a * b * b - 2 * b;
            } else {
                A[i][j] = 3 * a * b - 3;
            }
        }
    }
    return A;
}

int** transMatrix(int** A, int n){
    int** B = new int* [n];
    for (int i = 0; i < n; i++) {
        B[i] = new int[n];
        for (int j = 0; j < n; j++) {
            B[i][j] = A[j][i];
        }
    }
    return B;
}

//чет строки нечет столбцы
int sumA(int** A, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + 1) % 2 == 0 && (j + 1) % 2 != 0) {
                sum += A[i][j];
            }
        }
    }
    return sum;
}

//нечет строки чет столбцы
int sumB(int** B, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + 1) % 2 != 0 && (j + 1) % 2 == 0) {
                sum += B[i][j];
            }
        }
    }
    return sum;
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}