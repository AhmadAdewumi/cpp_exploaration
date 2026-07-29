#include <stdio.h>

/* Function to calculate factorial */
long calculate_factorial(int number) {
    long factorial_result = 1;
    int i;
    for (i = 1; i <= number; i++) {
        factorial_result = factorial_result * i;
    }
    return factorial_result;
}

/* Function to reverse an array */
void reverse_array(int arr[], int array_size) {
    int start_index = 0;
    int end_index   = array_size - 1;
    int temp;

    while (start_index < end_index) {
        temp                  = arr[start_index];
        arr[start_index]      = arr[end_index];
        arr[end_index]        = temp;
        start_index++;
        end_index--;
    }
}

int main() {

    int user_choice;
    int number_to_factorial;
    int array_to_reverse[50];
    int array_size;
    int i;

    /* Keep running until user chooses Exit */
    while (1) {

        /* Display menu */
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Print factorial of a number\n");
        printf("2. Reverse an integer array\n");
        printf("3. Exit\n");
        printf("Please select your choice (1 to 3): ");
        scanf("%d", &user_choice);

        if (user_choice == 1) {

            printf("Enter a number: ");
            scanf("%d", &number_to_factorial);
            printf("Factorial of %d = %ld\n", 
                   number_to_factorial, 
                   calculate_factorial(number_to_factorial));

        } else if (user_choice == 2) {

            printf("How many elements in array? ");
            scanf("%d", &array_size);

            printf("Enter %d elements:\n", array_size);
            for (i = 0; i < array_size; i++) {
                printf("Element %d: ", i + 1);
                scanf("%d", &array_to_reverse[i]);
            }

            reverse_array(array_to_reverse, array_size);

            printf("Reversed Array: ");
            for (i = 0; i < array_size; i++) {
                printf("%d ", array_to_reverse[i]);
            }
            printf("\n");

        } else if (user_choice == 3) {

            printf("Exiting program. Goodbye!\n");
            break;

        } else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}