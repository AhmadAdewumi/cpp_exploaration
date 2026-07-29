#include <stdio.h>


float avgOf5numbers() {
  float num, sum = 0;
  int i;

  for (i = 0; i < 5; i++) {
    scanf("%f", &num);
    sum = sum + num;
  }

  return sum / 5;
}

int main() {
    float avg;
    printf("Enter 5 numbers: \n");
    avg = avgOf5numbers();
    printf("Average = %.2f\n", avg);
    
    return 0;
}