//
// Created by ahmad on 6/10/26.
//

#include <iostream>

int getValueFromUser() {
    std::cout << "Enter an Integer: ";
    int input{};
    std::cin >> input;
    return input;
}

int main() {
    int x{getValueFromUser()};
    int y{getValueFromUser()};

    std::cout << x << " + " << y << " = " << x + y << "\n";
    return 0;
}
