#include <cmath>

double recFunc(double arr[], int start, int end) {
    int n = end - start + 1;

    if (n == 1) {
        return sin(arr[start]) - cos(arr[start]);
    }
    if (n == 2) {
        return (sin(arr[start]) - cos(arr[start])) *
               (sin(arr[start + 1]) - cos(arr[start + 1]));
    }

    int firstThirdSize = n / 3;

    //хотя бы 1 элемент в каждой части
    if (firstThirdSize < 1) {
        firstThirdSize = 1;
    }

    int firstThirdEnd = start + firstThirdSize - 1;

    //вторая часть не пустая
    if (firstThirdEnd >= end) {
        firstThirdEnd = end - 1;
    }

    double firstPart = recFunc(arr, start, firstThirdEnd);
    double secondPart = recFunc(arr, firstThirdEnd + 1, end);

    return firstPart * secondPart;
}