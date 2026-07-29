#include <stdio.h>

/* Function that reads 5 numbers and returns their average */
double read_and_calculate_average() {

    double numbers[5];
    double sum = 0.0;
    int i;

    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%lf", &numbers[i]);
        sum = sum + numbers[i];
    }

    return sum / 5;
}

int main() {

    double average_result;

    /* Call the function from main */
    average_result = read_and_calculate_average();

    printf("\nAverage of the 5 numbers = %.2f\n", average_result);

    return 0;
}