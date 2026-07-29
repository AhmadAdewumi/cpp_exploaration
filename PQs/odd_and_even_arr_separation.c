#include <stdio.h>

int main() {

    int original_array[100];
    int even_numbers[100];
    int odd_numbers[100];
    int array_size;
    int even_count = 0;
    int odd_count  = 0;
    int i;

    printf("How many numbers? ");
    scanf("%d", &array_size);

    printf("Enter %d numbers:\n", array_size);
    for (i = 0; i < array_size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &original_array[i]);
    }

    /* Separate into even and odd arrays */
    for (i = 0; i < array_size; i++) {

        if (original_array[i] % 2 == 0) {
            even_numbers[even_count] = original_array[i];
            even_count++;
        } else {
            odd_numbers[odd_count] = original_array[i];
            odd_count++;
        }
    }

    /* Display even numbers */
    printf("\nEven Numbers: ");
    for (i = 0; i < even_count; i++) {
        printf("%d ", even_numbers[i]);
    }

    /* Display odd numbers */
    printf("\nOdd Numbers:  ");
    for (i = 0; i < odd_count; i++) {
        printf("%d ", odd_numbers[i]);
    }

    printf("\n");

    return 0;
}