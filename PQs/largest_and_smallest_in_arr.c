#include <stdio.h>

int main() {

    int numbers[100];
    int largest;
    int smallest;
    int i;

    /* Read 100 numbers from user */
    printf("Enter 100 numbers:\n");
    for (i = 0; i < 100; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    /* Assume first number is both largest and smallest */
    largest  = numbers[0];
    smallest = numbers[0];

    /* Compare each number with current largest and smallest */
    for (i = 1; i < 100; i++) {

        if (numbers[i] > largest) {
            largest = numbers[i];
        }

        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    printf("\nLargest Number  : %d\n", largest);
    printf("Smallest Number : %d\n", smallest);

    return 0;
}