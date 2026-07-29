#include <stdio.h>

/* Function to print elements divisible by divisor */
void print_divisible_elements(int number_array[], 
                               int array_size, 
                               int divisor) {

    int i;

    /* Check if divisor is zero */
    if (divisor == 0) {
        printf("Error: Cannot divide by zero.\n");
        return;
    }

    printf("Elements divisible by %d:\n", divisor);

    for (i = 0; i < array_size; i++) {
        if (number_array[i] % divisor == 0) {
            printf("%d\n", number_array[i]);
        }
    }
}

int main() {

    int number_array[500];
    int array_size;
    int divisor;
    int i;

    printf("How many numbers (max 500)? ");
    scanf("%d", &array_size);

    printf("Enter %d numbers:\n", array_size);
    for (i = 0; i < array_size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &number_array[i]);
    }

    printf("Enter divisor: ");
    scanf("%d", &divisor);

    /* Call function */
    print_divisible_elements(number_array, array_size, divisor);

    return 0;
}