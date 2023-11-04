#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <time.h>

// Можно использовать любую из функций GetCurrentDay() - обе должны работать

size_t GetCurrentDay() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    return st.wDay;
}

// size_t GetCurrentDay() {
//     struct tm buf;
//     time_t t = time(NULL);
//     return localtime(&t)->tm_mday;
// }

template <typename T>
void FillArray(T& arr, const size_t& array_size) {
    for (int i = 0; i < array_size; ++i) {
        for (int j = 0; j < array_size; ++j) {
            arr[i][j] = i + j;
        }
    }
}

template <typename T>
void PrintArray(const T& arr, const size_t& array_size) {
    for (int i = 0; i < array_size; ++i) {
        bool space = true;
        for (int j = 0; j < array_size; ++j) {
            if (!space) {
                std:: cout << " ";
            }
            space = false;
            std:: cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}

template <typename T>
size_t GetSumByDay(size_t N, const T& arr) {
    size_t sum = 0;
    size_t line_index = GetCurrentDay() % N;

    for (size_t k = 0; k < N; ++k) {
        sum += arr[line_index][k];
    }

    return sum;
}


int main() {
    const int N = 5;
    int arr[N][N];

    FillArray(arr, N);
    PrintArray(arr, N);
    
    std::cout << "\nThe sum is " << GetSumByDay(N, arr);
    return 0;
}

