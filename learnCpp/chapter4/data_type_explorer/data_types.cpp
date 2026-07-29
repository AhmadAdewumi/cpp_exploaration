//
// Created by ahmad on 7/19/26.
//
#include "data_types.h"
#include "iostream"
#include <cstdint>

void printSizeInfo() {
    std::cout << "\n=== DATA TYPE SIZES ===\n";
    std::cout << "bool:             " << sizeof(bool) << " bytes\n";
    std::cout << "char:             " << sizeof(char) << " bytes\n";
    std::cout << "short:            " << sizeof(short) << " bytes\n";
    std::cout << "int:              " << sizeof(int) << " bytes\n";
    std::cout << "long:             " << sizeof(long) << " bytes\n";
    std::cout << "long log:         " << sizeof(long long) << " bytes\n";
    std::cout << "float:            " << sizeof(float) << " bytes\n";
    std::cout << "double:           " << sizeof(double) << " bytes\n";
    std::cout << "int16_t:          " << sizeof(std::int16_t) << " bytes\n";
    std::cout << "int32_t:          " << sizeof(std::int32_t) << " bytes\n";
    std::cout << "int64_t:          " << sizeof(std::int64_t) << " bytes\n";
    std::cout << "=============================\n";
}

int charToASCII(char ch) {
    return static_cast<int>(ch);
}

void demonstrateOverflow() {
    std::cout << "\n=== Overflow Demo===";
    constexpr int c = {2147483647};
    std::cout << "Overflow occurs: " << c + 1 << "\n";
}

bool isPrime(int x) {
    if (x == 2 || x == 3 || x == 5 || x == 7 || x == 9)
        return true;
    return false;
}
