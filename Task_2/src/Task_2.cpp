#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>  // для LoadLibrary, GetProcAddress, FreeLibrary

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

void checkInputIntK(int& k) {
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

void checkInputArray(double& x) {
    while (true) {
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "Input error.\n";
            continue;
        }
        std::stringstream ss(line);
        if (ss >> x && ss.eof()) {
            break;
        } else {
            std::cout << "Incorrect input.\n";
        }
    }
}

void Task() {
    // 1. ЗАГРУЖАЕМ ДИНАМИЧЕСКУЮ БИБЛИОТЕКУ
    HINSTANCE load;
    load = LoadLibrary("RecDLL.dll");
    if (load == nullptr) {
        std::cout << "Ошибка: не удалось загрузить RecDLL.dll!" << std::endl;
        return;
    }

    // 2. ОБЪЯВЛЯЕМ ТИПЫ УКАЗАТЕЛЕЙ НА ФУНКЦИИ ИЗ DLL
    typedef double (__stdcall *RecFunc)(double[], int, int);

    // 3. ПОЛУЧАЕМ УКАЗАТЕЛИ НА ФУНКЦИИ ИЗ DLL
    RecFunc pRecFunc;
    pRecFunc = (RecFunc)GetProcAddress(load, "recFunc");

    // Проверяем, что все функции найдены
    if (pRecFunc == nullptr) {
        std::cout << "Ошибка: не удалось найти функции в библиотеке!" << std::endl;
        FreeLibrary(load);
        return;
    }

    int n;
    std::cout << "Enter amount of massive: ";
    checkInputIntK(n);
    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Enter a" << i << ": ";
        checkInputArray(arr[i]);
    }
    std::cout << pRecFunc(arr, 0, n - 1) << std::endl;

    // 5. ВЫГРУЖАЕМ БИБЛИОТЕКУ ИЗ ПАМЯТИ
    FreeLibrary(load);
}

void Menu() {
    std::cout << "\tTask 2\n";
    std::cout << "\tVariant 9\n";
    std::cout << "The number of factors is specified.\n"
                 "Using a recursive function, the code calculates the product of factors using the formula:\n"
                 "sinCi - cosCi\n" << std::endl;
    std::cout << "Creator: Kseniya Siamionava\n" << std::endl;
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

