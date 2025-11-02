#include "MatrixDLL.h"

int __stdcall countEvenColumnOddNumber(int** arr, int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j % 2 != 0) {
                if (arr[i][j] % 2 != 0)
                    count++;
            }
        }
    }
    return count;
}

void __stdcall fillOut(int** arr, int* arr2, int m, int n) {
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j % 2 != 0) {
                if (arr[i][j] % 2 != 0)
                    arr2[index++] = arr[i][j];
            }
        }
    }
}

double __stdcall findAverage(int* arr, int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum / count;
}