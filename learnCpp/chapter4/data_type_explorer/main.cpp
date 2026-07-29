//
// Created by ahmad on 7/19/26.
//
#include <iostream>
#include "data_types.h"
#include "io.h"

void showCharacterDemo() {
    char ch{getCharacter()};
    int asciiValue{ charToASCII(ch)};

    std::cout << "You entered " << ch << "\n";
    std::cout << "ASCII CODE: " << asciiValue << "\n";
    std::cout << "Next Character: '" << static_cast<char>(asciiValue + 1) << "'\n";
    std::cout << "Is it a digit?";

    if (asciiValue >= 47 && asciiValue <= 57)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    std::cout << "Is it a letter? ";
    if ((asciiValue >= 47 && asciiValue <=65) || (asciiValue >= 97 && asciiValue <= 122))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}

void showIntegerDemo() {
    int x{getInteger()};

    std::cout << "You entered: " << x << "\n";
    std::cout << "Double that: " << x * 2 << "\n";
    std::cout << "Square: " << x * x << "\n";
    std::cout << "Is it prime? ";

    if (isPrime(x))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}

void showDoubleDemo()
{
    double x{ getDouble() };

    std::cout << "You entered: " << x << "\n";
    std::cout << "Rounded to int: " << static_cast<int>(x) << "\n";
    std::cout << "Half of that: " << x / 2.0 << "\n";
    std::cout << "Is it greater than 10? ";

    if (x > 10.0)
        std::cout << "Yes\n\n";
    else
        std::cout << "No\n\n";
}

int main() {
    std::cout << "=== DATA TYPE EXPLORER ===";
    printSizeInfo();

    showCharacterDemo();
    showIntegerDemo();
    showDoubleDemo();

    demonstrateOverflow();

    return 0;
}