#include <stdio.h>
#include <math.h>

int main() {

    double coefficient_a;
    double coefficient_b;
    double coefficient_c;
    double discriminant;
    double root_one;
    double root_two;
    double real_part;
    double imaginary_part;

    printf("Enter coefficient a: ");
    scanf("%lf", &coefficient_a);

    printf("Enter coefficient b: ");
    scanf("%lf", &coefficient_b);

    printf("Enter coefficient c: ");
    scanf("%lf", &coefficient_c);

    /* Calculate discriminant */
    discriminant = (coefficient_b * coefficient_b) - 
                   (4 * coefficient_a * coefficient_c);

    printf("\nDiscriminant = %.2f\n", discriminant);

    if (discriminant > 0) {

        /* Two distinct real roots */
        root_one = (-coefficient_b + sqrt(discriminant)) / 
                   (2 * coefficient_a);
        root_two = (-coefficient_b - sqrt(discriminant)) / 
                   (2 * coefficient_a);

        printf("Two distinct real roots:\n");
        printf("Root 1 = %.2f\n", root_one);
        printf("Root 2 = %.2f\n", root_two);

    } else if (discriminant == 0) {

        /* Two equal real roots */
        root_one = -coefficient_b / (2 * coefficient_a);

        printf("Two equal real roots:\n");
        printf("Root 1 = Root 2 = %.2f\n", root_one);

    } else {

        /* Complex roots */
        real_part      = -coefficient_b / (2 * coefficient_a);
        imaginary_part = sqrt(-discriminant) / (2 * coefficient_a);

        printf("Complex roots:\n");
        printf("Root 1 = %.2f + %.2fi\n", real_part, imaginary_part);
        printf("Root 2 = %.2f - %.2fi\n", real_part, imaginary_part);
    }

    return 0;
}