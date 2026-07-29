#include <iostream>
//
// Created by ahmad on 7/19/26.
//
int main() {
    std::cout << "Would you like a burrito (y/n): \n";
    char x{};
    std::cin >> x;

    if (x == 'y') {
        std::cout << "Burrito it is \n";
    }
    else if (x == 'n') {
        std::cout << "Yikes, you do not want a burrito\n";
    }
    else {
        std::cout << "Please enter a valid character: (y or n) \n";
    }

    return 0;
}