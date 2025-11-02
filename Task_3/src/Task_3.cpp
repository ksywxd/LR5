#include <iostream>

int** creatMatrix(int n, int k) {
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[k];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << "a" << i << j << ":" << std::endl;
            std::cin >> arr[i][j];
        }
    }

    return arr;
}

int* findElOnD(int* arr[], int n, int k, int& count) {
    int diagSize = std::min(n, k);
    for (int i = 0; i < diagSize; i++) {
        if (arr[i][i] % 2 == 0) {
            count++;
        }
    }

    if (count == 0) {
        std::cout << "No even elements found on the main diagonal" << std::endl;
        return nullptr;
    }
    else {
        int* onD = new int[count];
        int index = 0;
        for (int i = 0; i < diagSize; i++) {
            if (arr[i][i] % 2 == 0) {
                onD[index++] = arr[i][i];
            }
        }
        return onD;
    }
}

int multiply(int* onD, int count) {
    int res = 1;
    for (int i = 0; i < count; i++) {
        res *= onD[i];
    }
    return res;
}

int main() {
    int n, k;
    std::cout << "n: " << std::endl;
    std::cin >> n;
    std::cout << "k: " << std::endl;
    std::cin >> k;

    int** arr = creatMatrix(n, k);
    int count = 0;
    int* onD = findElOnD(arr, n, k, count);

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    if (onD != nullptr) {
        std::cout << "Even elements on main diagonal: ";
        for (int i = 0; i < count; i++) {
            std::cout << onD[i] << " ";
        }
        std::cout << "\nResult of multiply: " << multiply(onD, count) << std::endl;
        delete[] onD;
    }

    return 0;
}