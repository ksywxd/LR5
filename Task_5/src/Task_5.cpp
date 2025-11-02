#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>  // для LoadLibrary, GetProcAddress, FreeLibrary

// Объявляем указатели на функции как глобальные переменные
typedef int(__stdcall* CountFunc)(int**, int, int);
typedef void(__stdcall* FillFunc)(int**, int*, int, int);
typedef double(__stdcall* AverageFunc)(int*, int);

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

void checkInputArray(int& x){
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

int** createMatrix(int m, int n) {
    int** arr = new int*[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "a" << i << j << ": ";
            checkInputArray(arr[i][j]);
        }
    }

    return arr;
}

/*int countEvenColumnOddNumber(int** arr, int m, int n) {
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
}*/

/*void fillOut(int** arr, int* arr2, int m, int n) {
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j % 2 != 0) {
                if (arr[i][j] % 2 != 0)
                arr2[index++] = arr[i][j];
            }
        }
    }
}*/

void printInitial(int** arr, int m, int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printDynamic(int* arr, int count) {
    for (int i = 0; i < count; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/*double findAverage(int* arr, int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum / count;
}*/

void freeArr(int** arr, int m) {
    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

}

void Task() {
    // 1. ЗАГРУЖАЕМ ДИНАМИЧЕСКУЮ БИБЛИОТЕКУ
    HINSTANCE hDLL = LoadLibrary("MatrixDLL.dll");
    if (hDLL == nullptr) {
        std::cout << "Ошибка: не удалось загрузить MatrixDLL.dll!" << std::endl;
        return;
    }

    // 2. ОБЪЯВЛЯЕМ ТИПЫ УКАЗАТЕЛЕЙ НА ФУНКЦИИ ИЗ DLL
    // Тип для функции countEvenColumnOddNumber
    typedef int (__stdcall *CountFunc)(int**, int, int);

    // Тип для функции fillOut
    typedef void (__stdcall *FillFunc)(int**, int*, int, int);

    // Тип для функции findAverage
    typedef double (__stdcall *AverageFunc)(int*, int);

    // 3. ПОЛУЧАЕМ УКАЗАТЕЛИ НА ФУНКЦИИ ИЗ DLL
    auto countEvenColumnOddNumber = reinterpret_cast<CountFunc>(GetProcAddress(hDLL, "countEvenColumnOddNumber"));
    auto fillOut = reinterpret_cast<FillFunc>(GetProcAddress(hDLL, "fillOut"));
    auto findAverage = reinterpret_cast<AverageFunc>(GetProcAddress(hDLL, "findAverage"));

    // Проверяем, что все функции найдены
    if (countEvenColumnOddNumber == nullptr || fillOut == nullptr || findAverage == nullptr) {
        std::cout << "Ошибка: не удалось найти функции в библиотеке!" << std::endl;
        FreeLibrary(hDLL);
        return;
    }

    int n = 0, m = 0;
    std::cout << "m: ";
    checkInputIntK(m);
    std::cout << "n: ";
    checkInputIntK(n);

    int** arr = createMatrix(m, n);
    std::cout << "Initial massive:" << std::endl;
    printInitial(arr, m, n);

    int count = countEvenColumnOddNumber(arr, m, n);

    if (count != 0) {
        int* evenColumnOddNumberArr = new int[count];
        fillOut(arr, evenColumnOddNumberArr, m, n);

        freeArr(arr, m);

        std::cout << "Odd numbers in even columns:" << std::endl;
        printDynamic(evenColumnOddNumberArr, count);

        std::cout << "Arithmetic mean: " << findAverage(evenColumnOddNumberArr, count) << std::endl;

        delete[] evenColumnOddNumberArr;
    } else {
        freeArr(arr, m);
        std::cout << "No such numbers" << std::endl;
    }

    // 5. ВЫГРУЖАЕМ БИБЛИОТЕКУ ИЗ ПАМЯТИ
    FreeLibrary(hDLL);
}

void Menu() {
    std::cout << "\tTask 5\n";
    std::cout << "Show odd numbers in even columns\n" << std::endl;
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