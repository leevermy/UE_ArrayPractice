#include <iostream>
#include <windows.h>


size_t GetCurrentDay() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    return st.wDay;
}


void FillArray(int* const arr, const size_t& array_size) {
    for (int i = 0; i < array_size; ++i) {
        for (int j = 0; j < array_size; ++j) {
            *(arr + i + j) = i + j;
        }
    }
}

void PrintArray(const int* const arr, const size_t& array_size) {
    for (int i = 0; i < array_size; ++i) {
        bool space = true;
        for (int j = 0; j < array_size; ++j) {
            if (!space) {
                std:: cout << " ";
            }
            space = false;
            std:: cout << *(arr + i + j);
        }
        std::cout << std::endl;
    }
}

size_t GetSumByDay(size_t N, const int* arr) {
    size_t sum = 0;
    size_t line_index = GetCurrentDay() % N;

    for (size_t k = 0; k < N; ++k) {
        sum += *(arr + line_index + k);
    }

    return sum;
}


int main() {
    const int N = 5;
    int arr[N][N];

    FillArray((int*)arr, N);
    PrintArray((int*)arr, N);
    
    std::cout << "\nThe sum is " << GetSumByDay(N, (int*)arr);
    return 0;
}