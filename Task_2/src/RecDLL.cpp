#include "RecDLL.h"
#include <cmath>

double __stdcall recFunc(double arr[], int start, int end) {
    int n = end - start + 1;
    if (n == 1) return sin(arr[start]) - cos(arr[start]);
    if (n ==2) return (sin(arr[start]) - cos(arr[start])) * (sin(arr[start]) - cos(arr[start]));

    int part = n / 3;

    return recFunc(arr, start, part - 1) * recFunc(arr, part, end);
}