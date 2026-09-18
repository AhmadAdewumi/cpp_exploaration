#include <iostream>

int main() {
  int x{42};

  std::cout << "x     = " << x << "\n";
  std::cout << "&x i.e. address of x      = " << &x << "\n";

  // declare a pointer p that point to an address that contains an int and init
  // it with the address of x
  int *p{&x};
  std::cout << "p     = " << p << "\n";
  std::cout << "*p     = " << *p << "\n"; // dereferencing p

  *p = 100; // got to the address p points to and change the value to 100
  std::cout << "x     = " << x << "\n"; // x should be 100 also
  std::cout << "p     = " << p << "\n";

  // wild pointer
  int *c; //contains garbage address initially
  *c = 15;
  std::cout << "c     = " << c << "\n";
}
