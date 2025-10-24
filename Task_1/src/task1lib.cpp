#include <iostream>
#include <sstream>
#include <string>
#include "task1lib.h"

void checkInputChoice(int& choice) {
    while (true) {
        std::cout << "Start?\n1.YES\n2.EXIT\n3.Show menu\n";
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "Input error.\n";
            continue;
        }
        std::stringstream ss(line);
        if (ss >> choice && ss.eof()) {
            if (choice >= 1 && choice <= 3) {
                break; // одно число в диапазоне и ничего больше
            }
            else {
                std::cout << "Incorrect input. Enter 1, 2, or 3.\n";
            }
        }
        else {
            std::cout << "Incorrect input. Enter a single number.\n";
        }
    }
}

void checkInputIntK(int& k){
    while (true) {
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "Input error.\n";
            continue;
        }
        std::stringstream ss(line);
        if (ss >> k && ss.eof()) {
            if (k < 1) {
                std::cout << "Input error" << std::endl;
                continue;
            } else {
                break;
            }
        } else {
            std::cout << "Incorrect input.\n";
        }
    }
}

void Menu() {
    std::cout << "\tTask 1\n";
    std::cout << "\tVariant 9\n" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "Creator: Kseniya Siamionava\n" << std::endl;
}

int** createMatrixA(int n){
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int [n];
        for (int j = 0; j < n; j++) {
            int a = i + 1;
            int b = j + 1;
            if (i <= 5) {
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

void Task() {
    int n;
    std::cout << "Enter matrix size:" << std::endl;
    checkInputIntK(n);

    int** A = createMatrixA(n);
    int** B = transMatrix(A, n);

    std::cout << "Matrix A:" << std::endl;
    printMatrix(A, n);
    std::cout << "Sum for A: " << sumA(A, n) << std::endl;

    std::cout << "Matrix B:" << std::endl;
    printMatrix(A, n);
    std::cout << "Sum for B: " << sumB(B, n) << std::endl;

    freeMatrix(A, n);
    freeMatrix(B, n);
}