#ifndef LR5_TASK1LIB_H
#define LR5_TASK1LIB_H

void checkInputChoice(int& choice);
void checkInputIntK(int& k);
int** createMatrixA(int n);
int** transMatrix(int** A, int n);
int sumA(int** A, int n);
int sumB(int** B, int n);
void printMatrix(int** matrix, int n);
void freeMatrix(int** matrix, int n);
void Task();
void Menu();

#endif //LR5_TASK1LIB_H