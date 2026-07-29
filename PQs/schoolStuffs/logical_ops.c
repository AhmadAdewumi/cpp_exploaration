#include <stdio.h>

int main() {
  int age = 20;
  int score = 75;

  if (age >= 18 && score >= 70) {
    printf("Student qualifies \n");
  }

  if (age < 18 || score >= 70) {
    printf("Student qualifies only on a condition not both \n");
  }

  if (!(age < 18)) {
    printf("Age is not less than 18 \n");
  }
}
