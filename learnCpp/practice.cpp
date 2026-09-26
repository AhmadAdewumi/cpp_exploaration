//
// Created by ahmad on 5/24/26.
//

#include <iostream>

int main() {
  // int x{}, y{}, z{};
  //
  // std::cout << "Enter three numbers separated by spaces: ";
  // std::cin >> x >> y >> z;
  // std::cout << "\nYou entered: " << x  << ", " << y << ", " << z << "\n";
  // return 0;

  int age{};
  int height{};

  std::cout << "Enter your age: ";
  std::cin >> age;
  std::cout << "Enter your height: ";
  std::cin >> height;

  std::cout << "Age: " << age << ", Height: " << height << "\n";
  return 0;
}
