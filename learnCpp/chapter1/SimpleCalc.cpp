//
// Created by ahmad on 5/25/26.
//

#include <iostream>
    int main() {
  int x{}, y{};

  std::cout << "Enter first number: ";
  std::cin >> x;

  std::cout << "Enter second number: ";
  std::cin >> y;

  std::cout << "sum: " << x + y << " diff: " << x - y << " product: " << x * y
            << " quotient: " << x / y << "\n";
  return 0;
}
