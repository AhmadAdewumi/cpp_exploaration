#include <stdio.h>

/* Function to check if a number is prime */
int is_prime(int number) {
    int i;

    if (number < 2) {
        return 0;  /* Not prime */
    }

    for (i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return 0;  /* Not prime — divisible by i */
        }
    }

    return 1;  /* Prime */
}

int main() {

    int numbers[100];
    int array_size;
    int sum_of_primes = 0;
    int i;

    printf("How many numbers? ");
    scanf("%d", &array_size);

    printf("Enter %d numbers:\n", array_size);
    for (i = 0; i < array_size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    /* Check each number and add to sum if prime */
    for (i = 0; i < array_size; i++) {
        if (is_prime(numbers[i])) {
            sum_of_primes = sum_of_primes + numbers[i];
        }
    }

    printf("\nSum of all prime numbers in array = %d\n", sum_of_primes);

    return 0;
}