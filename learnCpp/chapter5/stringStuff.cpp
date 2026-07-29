#include <iostream>
//
// Created by ahmad on 7/24/26.
//
int main() {
    // testing the std::getline() pitfall
    std::cout << "Enter a number: ";
    int choice{};
    //it wil only read the number and not the string
    // as the enter line is still being kept in the inputbuffer after reaiding the number
    std::cin >> choice;

    //TO RESOLVE THAT WE USE std::cin.ignore()
    std::cin.ignore(choice, '\n');

    std::cout << "Enter your name: ";
    std::string name{};
    std::getline(std::cin, name);

    int nameLength{static_cast<int>(std::size(name))};

    std::cout << "You picked: " << choice << "\n";
    std::cout << "Your name is: " << name << " and name length is: " << nameLength << "\n";
}
