#include <stdio.h>

int main() {

    int numbers[100];
    int size;
    int temp;
    int i;
    int j;

    printf("How many numbers do you want to enter? ");
    scanf("%d", &size);

    /* Read numbers into array */
    printf("Enter %d numbers:\n", size);
    for (i = 0; i < size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    /* Sort in ASCENDING order using bubble sort */
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {

            if (numbers[j] > numbers[j + 1]) {
                /* Swap */
                temp         = numbers[j];
                numbers[j]   = numbers[j + 1];
                numbers[j+1] = temp;
            }
        }
    }

    /* Display ascending order */
    printf("\nAscending Order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    /* Display descending order by reading array backwards */
    printf("\n\nDescending Order:\n");
    for (i = size - 1; i >= 0; i--) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}