//
// Created by ahmad on 7/19/26.
//
#include <iostream>
#include "io.h"
#include "data_types.h"

char getCharacter() {
    std::cout << "Enter a character: ";
    char ch{};
    std::cin >> ch;
    return ch;
}

int getInteger() {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

double getDouble() {
    std::cout << "Enter a double: ";
    double x{};
    std::cin >> x;
    return x;
}
