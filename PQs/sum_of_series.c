#include <stdio.h>
#include <math.h>

int main() {

    double x_value;
    int number_of_terms;
    double series_sum = 0.0;
    double current_term;
    double sign = 1.0;
    int i;

    printf("Enter value of x: ");
    scanf("%lf", &x_value);

    printf("Enter number of terms: ");
    scanf("%d", &number_of_terms);

    /* Calculate each term and add to sum */
    for (i = 1; i <= number_of_terms; i++) {

        /* Each term is i / x^i */
        current_term = sign * (i / pow(x_value, i));

        series_sum = series_sum + current_term;

        /* Alternate sign for next term */
        sign = sign * -1;
    }

    printf("\nSum of series = %.6f\n", series_sum);

    return 0;
}