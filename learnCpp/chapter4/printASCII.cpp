#include <iostream>
//
// Created by ahmad on 7/19/26.
//
int main() {
    std::cout << "Enter a character: ";
    char c;

    std::cin >> c;

    std::cout << "The ASCII code for the char entered is: " << static_cast<int>(c) << " \n"; //explicit convesion
    std::cout << "The ASCII code for the char entered is: " << c + 0 << " \n"; // implicit conversion

    return 0;
}