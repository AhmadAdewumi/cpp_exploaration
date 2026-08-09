#include <iostream>
#include "StaticArray.h"
#include "Math.h"
#include "Matrix.h"

//
// Created by ahmad on 8/8/26.
//

int main() {
    std::cout << maximum(10, 20) << "\n";
    std::cout << maximum(3.5, 2.1) << "\n";
    std::cout << maximum('b', 'z') << "\n";

    constexpr int result{maximum(30, 40)};
    static_assert(result == 40);

    constexpr double result0(maximum(10, 20.5));
    std::cout << typeid(result0).name() << "\n";

    //-- array test
    // StaticArray<int, 9> numbers;
    constexpr StaticArray<int, 6> numbers{5, 6, 7, 8, 9, 45};
    std::cout << numbers.size() << "\n";

    // numbers[0] = 5;
    // numbers[1] = 7;
    std::cout << "number at idx 0: " << numbers[0] << "\n";
    std::cout << "number at idx 1: " << numbers[1] << "\n";

    constexpr int total{numbers.sum(numbers)};
    static_assert(total == 80);


    //-- matrix test
    constexpr Matrix<int, 2, 3> matrix{
        1, 2, 3,
        4, 5, 6
    };
    static_assert(matrix(0, 0) == 1);
    static_assert(matrix(0, 1) == 2);
    static_assert(matrix(0, 2) == 3);

    static_assert(matrix(1, 0) == 4);
    static_assert(matrix(1, 1) == 5);
    static_assert(matrix(1, 2) == 6);

    //assert rows and cols
    using MyMatrix = Matrix<int, 2, 3>;
    static_assert(MyMatrix::rows() == 2);
    static_assert(MyMatrix::cols() == 3);

    //-- this matrix multiplication should fail, coz the dimension must match and it should be determined during compilation
    // Matrix<int, 2, 3> A{2, 3};
    // Matrix<int, 2, 4> B{7,4};
    // auto C = A * B;

    std::cout << matrix(0, 0) << '\n';
    std::cout << matrix(0, 1) << '\n';

    constexpr int x{square(5)}; //works

    //-- not constant, so consteval blocks us
    // int n{};
    // std::cin  >> n;
    // int y{square(n)};

    return 0;
}
