#include <stdio.h>

int main() {
  int numbers[100];
  int largest_number;
  int smallest_number;
  int idx;

  for (idx = 0; idx < 100; idx++) {
    printf("Enter numnber %d: ", idx + 1);
    scanf("%d", &numbers[idx]);
  }

  largest_number = numbers[0];
  smallest_number = numbers[0];

  for (idx = 0; idx < 100; idx++) {
    if (numbers[idx] > largest_number) {
      largest_number = numbers[idx];
    }

    if (numbers[idx] < smallest_number) {
      smallest_number = numbers[idx];
    }
  }
  
  printf("Largest number = %d \n", largest_number);
  printf("Smallest number = %d \n", smallest_number);
  
  return 0;
}
