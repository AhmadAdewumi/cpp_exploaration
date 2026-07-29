//
// Created by ahmad on 7/19/26.
//

#include <iostream>

int main() {
    std::cout << "ENTER A NUMBER BETWEEN 0-9: ";
    int x{};
    std::cin >> x;

    if (x == 2 || x == 3 || x == 5 || x == 7 || x == 9)
        std::cout << "The digit is prime";
    else
        std::cout << "The digit ios not prime";

    return 0;

}
