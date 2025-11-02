#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>  // для LoadLibrary, GetProcAddress, FreeLibrary

// Объявляем указатели на функции как глобальные переменные
typedef double(__stdcall* RecFunc)(double[], int, int);
RecFunc recFunc = nullptr;

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

/*double recFunc(double arr[], int start, int end) {
    int n = end - start + 1;
    if (n == 1) return sin(arr[start]) - cos(arr[start]);
    if (n ==2) return (sin(arr[start]) - cos(arr[start])) * (sin(arr[start]) - cos(arr[start]));

    int part = n / 3;

    return recFunc(arr, start, part - 1) * recFunc(arr, part, end);
}*/

void Task() {
    // 1. ЗАГРУЖАЕМ ДИНАМИЧЕСКУЮ БИБЛИОТЕКУ
    HINSTANCE hDLL = LoadLibrary("RecDLL.dll");
    if (hDLL == nullptr) {
        std::cout << "Ошибка: не удалось загрузить RecDLL.dll!" << std::endl;
        return;
    }

    // 2. ОБЪЯВЛЯЕМ ТИПЫ УКАЗАТЕЛЕЙ НА ФУНКЦИИ ИЗ DLL
    // Тип для функции recFunc
    typedef double (__stdcall *RecFunc)(double[], int, int);

    // 3. ПОЛУЧАЕМ УКАЗАТЕЛИ НА ФУНКЦИИ ИЗ DLL
    auto recFunc = reinterpret_cast<RecFunc>(GetProcAddress(hDLL, "recFunc"));

    // Проверяем, что все функции найдены
    if (recFunc == nullptr) {
        std::cout << "Ошибка: не удалось найти функции в библиотеке!" << std::endl;
        FreeLibrary(hDLL);
        return;
    }

    int n;
    checkInputIntK(n);
    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << recFunc(arr, 0, n - 1) << std::endl;

    // 5. ВЫГРУЖАЕМ БИБЛИОТЕКУ ИЗ ПАМЯТИ
    FreeLibrary(hDLL);
}

void Menu() {
    std::cout << "\tTask 5\n";
    std::cout << "\tVariant 9\n";
    std::cout << "С помощью рекусивной функции вычисляется произведение\n"
                 "для заданного количества множителей по формуле\n"
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

