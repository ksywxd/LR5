#ifndef LR5_TASK1LIB_H
#define LR5_TASK1LIB_H

int** createMatrixA(int n);
int** transMatrix(int** A, int n);
int sumA(int** A, int n);
int sumB(int** B, int n);
void printMatrix(int** matrix, int n);
void freeMatrix(int** matrix, int n);

#endif //LR5_TASK1LIB_H