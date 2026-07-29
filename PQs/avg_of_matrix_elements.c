#include <stdio.h>

int main() {

    int matrix[10][10];
    int number_of_rows;
    int number_of_columns;
    int row;
    int col;
    double sum_of_elements = 0.0;
    double average;
    int total_elements;

    printf("Enter number of rows: ");
    scanf("%d", &number_of_rows);

    printf("Enter number of columns: ");
    scanf("%d", &number_of_columns);

    /* Read matrix elements */
    printf("Enter matrix elements:\n");
    for (row = 0; row < number_of_rows; row++) {
        for (col = 0; col < number_of_columns; col++) {
            printf("Element [%d][%d]: ", row + 1, col + 1);
            scanf("%d", &matrix[row][col]);
        }
    }

    /* Calculate sum of all elements */
    for (row = 0; row < number_of_rows; row++) {
        for (col = 0; col < number_of_columns; col++) {
            sum_of_elements = sum_of_elements + matrix[row][col];
        }
    }

    /* Calculate average */
    total_elements = number_of_rows * number_of_columns;
    average = sum_of_elements / total_elements;

    printf("\nSum of all elements = %.2f\n", sum_of_elements);
    printf("Total elements      = %d\n", total_elements);
    printf("Average             = %.2f\n", average);

    return 0;
}