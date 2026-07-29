#include <stdio.h>

int main() {
  int subjectMarks[10];
  int index;
  int totalMarks = 0;
  int largestMark;
  int smallestMark;
  float averageMark;

  for (index = 0; index < 10; index++) {
    printf("Enter mark for subject %d: ", index + 1);
    scanf("%d", &subjectMarks[index]);
  }

  for (index = 0; index < 10; index++) {
    totalMarks += subjectMarks[index];

    if (subjectMarks[index] > largestMark) {
      largestMark = subjectMarks[index];
    }

    if (subjectMarks[index] < smallestMark) {
      smallestMark = subjectMarks[index];
    }
  }
  
  averageMark = totalMarks / 10.0;

  printf("Total marks = %d\n", totalMarks);
  printf("Average mark = %.2f\n", averageMark);
  printf("Largest mark = %d\n", largestMark);
  printf("Smallest mark = %d\n", smallestMark);

  return 0;
}
}
