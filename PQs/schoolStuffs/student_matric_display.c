#include <stdio.h>

int main() {
  char names[50][50];
  char matric_no[50][20];
  
  int i;

  for (i = 0; i < 3; i++) {
    printf("Enter name of student %d: ", i + 1);
    scanf("%s", names[i]);

    printf("Enter  matric number of student %d: ", i + 1);
    scanf("%s", matric_no[i]);
  }

  printf("\nList of Students and Matric Numbers:\n");
  printf("------------------------------------\n");

  for (i = 0; i < 3; i++) {
      printf("%d. Name: %s\t Matric No: %s\n", i+1, names[i], matric_no[i]);
  }
  
  return 0;
}