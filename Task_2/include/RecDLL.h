#ifndef LR5_RECDLL_H
#define LR5_RECDLL_H

#ifdef __cplusplus
extern "C" {
#endif

    // Экспортируем функции из DLL
    __declspec(dllexport) int __stdcall recFunc(double arr[], int, int);

#ifdef __cplusplus
}
#endif

#endif //LR5_RECDLL_H