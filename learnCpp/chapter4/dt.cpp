#include <iomanip>
#include <iostream>
//
// Created by ahmad on 7/14/26.
//
int main() {
    bool myBool = true;
    char myChar = 'A';
    short myShort = 42;
    int myInt = 789;
    long long myLongLong = 73928349029347LL;
    long long myLong = 73928349029347L;
    float myFloat = 3.14f;
    double myDouble = 3.141456789;

    std::cout << std::left; //-- aligns texts to left side of columns

    // column 1: width = 16 characters | column 2 width = 16
    std::cout << std::setw(16) << "bool:" << std::setw(1) << std::to_string(sizeof(bool)) << " bytes -> " << myBool << "\n";
    std::cout << std::setw(16) << "char:" << std::setw(1) << std::to_string(sizeof(char))  << " bytes -> " << myChar << "\n";
    std::cout << std::setw(16) << "short:" << std::setw(1) << std::to_string(sizeof(short)) << " bytes -> " << myShort << "\n";
    std::cout << std::setw(16) << "long:" << std::setw(1) << std::to_string(sizeof(long))  << " bytes -> " << myLong << "\n";
    std::cout << std::setw(16) << "int:" << std::setw(1) << std::to_string(sizeof(int))  << " bytes -> " << myInt << "\n";
    std::cout << std::setw(16) << "long long:" << std::setw(1) << std::to_string(sizeof(long long))  << " bytes -> " << myLongLong << "\n";
    std::cout << std::setw(16) << "double:" << std::setw(1) << std::to_string(sizeof(double))  << " bytes -> " << myDouble << "\n";

    if (sizeof(int) == 4)
        std::cout << "My system has 4 bytes\n";
    else
        std::cout << "My system uses non 4 bytes for int\n";
    return 0;

}