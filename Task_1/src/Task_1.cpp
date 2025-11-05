#include "task1lib.h"
#include <iostream>
#include <sstream>
#include <string>

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
    std::cout << "A matrix of size n×n is formed.\n"
    "The elements are determined as follows:\n"
    "If i<=5: a[i][j] = 2ij^2 - 2j\n"
    "If i > 5: 3ij - 3\n"
    "The transposed matrix B is formed.\n"
    "The sum of the elements of the even rows and odd columns for matrix A\n"
    "and the sum of the even columns and odd rows for matrix B are determined.\n" << std::endl;
    std::cout << "Creator: Kseniya Siamionava\n" << std::endl;
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

int main() {
    int choice = 0;

    while (true) {
        checkInputChoice(choice);

        if (choice == 1) {
            Task();
        }
        else if (choice == 2) {
            break;
        }
        else if (choice == 3) {
            Menu();
        }
    }
    return 0;
}