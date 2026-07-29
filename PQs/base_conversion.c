// #include <stdio.h>
// #include <math.h>

// int main() {

//     int value;
//     int base;
//     int number_of_digits;
//     int current_digit;
//     int remaining_value;
//     int power_of_base;

//     printf("Enter 0 0 to stop.\n");

//     /* Keep reading pairs until user enters 0 0 */
//     while (1) {

//         printf("\nEnter value and base: ");
//         scanf("%d %d", &value, &base);

//         /* Stop if user enters 0 0 */
//         if (value == 0 && base == 0) {
//             printf("Program ended.\n");
//             break;
//         }

//         /* Check base is valid */
//         if (base < 2 || base > 10) {
//             printf("Base must be between 2 and 10.\n");
//             continue;
//         }

//         /* Calculate number of digits using the hint formula */
//         number_of_digits = (int)(log(value) / log(base)) + 1;

//         printf("%d in base %d is: ", value, base);

//         remaining_value = value;

//         /* Extract digits from most significant to least significant */
//         int i;
//         for (i = number_of_digits - 1; i >= 0; i--) {

//             power_of_base = (int)pow(base, i);

//             /* Get the current most significant digit */
//             current_digit = remaining_value / power_of_base;

//             /* Print the digit */
//             printf("%d", current_digit);

//             /* Remove that digit from remaining value */
//             remaining_value = remaining_value % power_of_base;
//         }

//         printf("\n");
//     }

//     return 0;
// }
//

#include <math.h>
#include <stdio.h>

int main() {
  int value;
  int base;
  int number_of_digit;
  int curr_digit;
  int remaining_value;
  int power_of_base;

  printf("Enter 0 0 to stop \n");

  while (1) {
    printf("Enter value and base: ");
    scanf("%d %d", &value, &base);

    if (value == 0 && base == 0) {
      printf("Program Ended");
      break;
    }

    if (base < 2 || base < 10) {
      printf("Base must be between 2 and 10.\n");
      continue;
    }

    number_of_digit = (int)(log(value) / log(base)) + 1;

    printf("%d in base %d is: ", value, base);
    
  }
}
