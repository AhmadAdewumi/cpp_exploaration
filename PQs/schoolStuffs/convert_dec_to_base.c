#include <math.h>
#include <stdio.h>

int main() {
  int decimalValue; //-- original no. in base 10
  int base;         //-- base we wanna convert to

  int digitCount; //-- how many digits willl the final answer have?
  
  /*
   * stores base^(digit position)
   * e.g for binary conversion
   * 2^4 = 16
   * 2^3 = 8
   * 2^2 = 4
   * 2^1 = 2
   * 2^0 = 1
   */
  int powerValue;
  int digit; //-- each digit of the result, e.g 11001, digits extracted 1 by 1

  printf("Enter decimal value: ");
  scanf("%d", &decimalValue); //-- &decimalValue means store this decimalValue input in that decimalValue memory address

  printf("Enter base to convert to (2-10): ");
  scanf("%d", &base);

  digitCount = (int)(log(decimalValue) / log(base)) + 1; //-- number of digits = log_base(n) + 1, But C only has log() (natural log), so we use: log_base(n) = log(n) / log(base)

  while (digitCount > 0) {
    powerValue = pow(base, digitCount - 1);

    digit = decimalValue / powerValue;

    printf("%d", digit);

    decimalValue = decimalValue % powerValue;

    digitCount--;
  }

  printf("\n");

  return 0;
}
