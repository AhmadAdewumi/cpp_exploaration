#include <stdio.h>

int main() {

    int current_number;
    long total_sum = 0;

    for (current_number = 1; current_number <= 1000; current_number++) {

        /* Skip numbers divisible by both 3 and 5 */
        if (current_number % 3 == 0 && current_number % 5 == 0) {
            continue;
        }

        total_sum = total_sum + current_number;
    }

    printf("Sum of numbers from 1 to 1000 ");
    printf("(excluding multiples of both 3 and 5) = %ld\n", total_sum);

    return 0;
}