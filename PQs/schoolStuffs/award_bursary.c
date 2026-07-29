#include <stdio.h>

int main() {
  int level;

  printf("Enter your level (100, 200, 300, 400): \n");
  scanf("%d", &level);

  switch (level) {

  case 100:
    printf("Bursary award is #10,000 \n");
    break;

  case 200:
    printf("Bursary award is #20,000 \n");
    break;

  case 300:
    printf("Bursary award is #30,000 \n");
    break;

  case 400:
    printf("Bursary award is #40,000 \n");
    break;

  default:
    printf("Invalid level entered \n");
  }

  return 0;
}
