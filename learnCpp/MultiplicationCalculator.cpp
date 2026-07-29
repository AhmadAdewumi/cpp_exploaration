//
// Created by ahmad on 5/24/26.
//
#include <iostream>

int main() {
    std::cout << "Enter a number: ";

    int num{};
    std::cin >> num;

    int doubleNum{num * 2};

    // std::cout << "Double that number is: " << doubleNum << '\n';
    //or
    std::cout << "Double that number is: " << num*2 << '\n';
    return 0;
}
