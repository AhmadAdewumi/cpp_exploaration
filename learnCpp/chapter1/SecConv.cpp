//
// Created by ahmad on 5/25/26.
//
#include  <iostream>

int main() {
    int noOfSeconds;

    std::cout << "Enter the value in seconds: ";

    std::cin >> noOfSeconds;

    std::cout << noOfSeconds / 60 << " minutes, " << noOfSeconds % 60 << " seconds \n";
    return 0;
}
